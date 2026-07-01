#include "Board.h"
#include "../Position.h"
#include <iostream>



Board::Board(const Player& player1,const Player& player2):
m_player1(player1),m_player2(player2)
{
    this->init();
}




void Board::init(){

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            m_pieces[i][j] = Piece::EMPTY;
        }
    }

    for(int i = 0;i<4;i++){
        m_amazon_list.push_back(Amazon(defaultAmazonPositions().at(i),m_player1));
    }
    for(int i = 4;i < 8;i++){
        m_amazon_list.push_back(Amazon(defaultAmazonPositions().at(i),m_player2));
    }
    

    for(const Amazon& amazon : m_amazon_list){
        m_pieces[amazon.getPosition().getX()][amazon.getPosition().getY()] = Piece::AMAZON;
        

    }
    
}







std::vector<Position> Board::defaultAmazonPositions(){
    std::vector<Position>defaultPositions;
    defaultPositions.push_back(Position(0,2));
    defaultPositions.push_back(Position(0,5));
    defaultPositions.push_back(Position(1,0));
    defaultPositions.push_back(Position(1,7));
    defaultPositions.push_back(Position(7,2));
    defaultPositions.push_back(Position(7,5));
    defaultPositions.push_back(Position(6,0));
    defaultPositions.push_back(Position(6,7));

    return defaultPositions;
}






bool Board::isOutOfBound(const Amazon& amazon)const{
    return amazon.getPosition().isOutOfBound(*this);
}


bool Board::isAmazon(Position& position){
    if( m_pieces[position.getX()][position.getY()]==Piece::AMAZON){
        return true;
    }
    return false;
}


Amazon& Board::getAmazon(Position& position){
    for(Amazon& amazon : m_amazon_list){
        if(amazon.getPosition().getX()== position.getX()&& 
        amazon.getPosition().getY() == position.getY()){
            return amazon;
        }

    }
    throw std::runtime_error("Amazon introuvable");
}



bool Board::isGameEnded()const{
    int count = 0;
    for(const Amazon& amazon : getPlayerAmazons(m_player1)){
        count++;
        if(count == 4){
            if(amazon.availablePositions(*this).size()==0){
                return true;
            }
        }
        if(amazon.availablePositions(*this).size()>0){
            break;
        }

    }

    count = 0;
    for(const Amazon& amazon : getPlayerAmazons(m_player2)){
                        count++;
        if(count == 4){
            if(amazon.availablePositions(*this).size()==0){
                return true;
            }
        }
        if(amazon.availablePositions(*this).size()>0){
            break;
        }

    }
    return false;
}








PlayerID Board::getWinner()const{
    if(this->isGameEnded()){
        if(this->getTurnCount() % 2 == 0){
            return m_player1.getPlayerID();
        }
        return m_player2.getPlayerID();
    }
    return PlayerID::NoPlayer;
}






std::vector<Amazon> Board::getPlayerAmazons(const Player& player)const{
    std::vector<Amazon>playerAmazons;
    for(const Amazon& amazon : m_amazon_list){
        if(amazon.getPlayer().getPlayerID() == player.getPlayerID()){
            playerAmazons.push_back(amazon);
        }
    }
    return playerAmazons;
}



void Board::setAmazonPosition(Amazon& amazon,const Position& position){
    for(Amazon& my_amazon : m_amazon_list){
        if(my_amazon.isEqual(amazon)){
            my_amazon.setPosition(position);
        }
    }
 }





void Board::setPiece(Piece piece, const Position& position){
    m_pieces[position.getX()][position.getY()] = piece;

}







bool Board::isEmpty(const Position& position)const{
    return m_pieces[position.getX()][position.getY()] == Piece::EMPTY;



}







void Board::moveAmazon(Amazon& amazon, const Position& position){
    if(amazon.canMoveTo(*this,position)){
        this->setPiece(Piece::EMPTY,amazon.getPosition());
        setAmazonPosition(amazon,position);

        this->setPiece(Piece::AMAZON,position);
    }

}




void Board::throwArrow(Amazon& amazon,const Position& position){
        if(amazon.canMoveTo(*this,position)){
            std::cout<<"yes it can throw arrow"<<std::endl;
            this->setPiece(Piece::ARROW,position);
        }
        else{
            std::cout<<"no it cannot throw arrow"<<std::endl;
        }
}






void Board::update(Amazon& amazon, Position& newAmazonPos, Position& arrowPos){
    this->moveAmazon(amazon,newAmazonPos);
    amazon.setPosition(newAmazonPos);
    this->throwArrow(amazon,arrowPos);
}







int Board::getTurnCount()const{
    return m_count_turn;
}





void Board::nextTurn(){
    m_count_turn++;
}



std::string Board::displayPiece(const Position& position){
    std::string result;
    if(m_pieces[position.getX()][position.getY()] == Piece::AMAZON){
        
        for(Amazon& amazon : m_amazon_list){
            if(amazon.getPosition().getX() == position.getX()
            &&amazon.getPosition().getY() == position.getY()){
                result+="A";
                if(amazon.getPlayer().getPlayerID() == PlayerID::Player1){
                    result+= "1";
                }
                else{
                    result+= "2";
                }
                
            }
        }
        
    }

    else if(m_pieces[position.getX()][position.getY()] == Piece::ARROW){
        result+= "XX";
    }
    else{
        result+= "  ";
    }

    return result;
}



std::string Board::toString(int row, int column){
    std::string boardString= "";

    for(int i = 0;i< row;i++){
        for(int j = 0;j < column ;j++){
            
            boardString += "+----";
            
            
        }
        boardString += "+";
        boardString+= "\n";
        
        for(int col = 0;col< column;col++){
            boardString+= "| ";
            boardString+= this->displayPiece(Position(i,col));
            boardString+= " ";

        }
        boardString+= "|";
        
        
        boardString+= "\n";
        
    }
    for(int j = 0;j < column ;j++){
    
        boardString += "+----";
    
    
    }
    boardString += "+";
    return boardString;

    
}

