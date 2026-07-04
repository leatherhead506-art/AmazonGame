#include"TerminalController.h"
#include<iostream>


TerminalController::TerminalController(Player& player1,Player& player2):
m_board(Board(player1,player2))
{
    
   
}



Board TerminalController::getBoard()const{
    return this->m_board;
}


void TerminalController::run(){
    while(!this->m_board.isGameEnded()){
        this->update();
    }
    if(this->m_board.getWinner()== PlayerID::Player1){
        std::cout << "le joueur 1 a gagné" << std::endl;
    }
    else{
        std::cout << "le joueur 2 a gagné" << std::endl;
    }
    
}


void TerminalController::update(){
    this->m_board.displayBoard();
    int x_amazon;
    int y_amazon;
    int x_new_position;
    int y_new_position;
    int x_arrow;
    int y_arrow;


    Position amazonPosition = Position(x_amazon,y_amazon);
    this->getAmazonPosition(x_amazon,y_amazon,amazonPosition);



    Position newAmazonPosition = Position(x_new_position,y_new_position);
    this->updateAmazonPosition(x_new_position,y_new_position,newAmazonPosition);



    Position arrowPosition = Position(x_arrow,y_arrow);
    this->updateArrowPosition(x_arrow,y_arrow,arrowPosition);


    
    Amazon amazon = this->m_board.getAmazon(amazonPosition);
    this->m_board.update(amazon,newAmazonPosition,arrowPosition);


    this->m_board.nextTurn();
    

}


void TerminalController::getAmazonPosition(int x, int y, Position& amazonPosition){
    std::cout<<"entre la coordonnéé x de l'amazone : "<<std::endl;
    std::cin >>x ;
    std::cout<<"entre la coordonnéé y de l'amazone : "<<std::endl;
    std::cin>>y;
    amazonPosition = Position(x,y);



    while(!this->m_board.isAmazon(amazonPosition)
        || !this->m_board.getAmazonPlayer(this->m_board.getAmazon(amazonPosition),
            this->m_board.getPlayerByTurn())){

        std::cout<<"tu t'es trompé sur la coordonée de l'amazon ou tu as selectionné l'amazone d'un autre joueuer"<<std::endl;

            

        std::cout<<"entre la bonne coordonnéé x de l'amazone : "<<std::endl;
        std::cin >>x;
        std::cout<<"entre la bonne coordonnéé y de l'amazone : "<<std::endl;
        std::cin>>y;
        amazonPosition = Position(x,y);
    



    }

}








void TerminalController::updateAmazonPosition(int newX, int newY, Position& newAmazonPosition){



    std::cout<<"entre la coordonnéé destination x de l'amazone : "<<std::endl;
    std::cin >>newX ;
    std::cout<<"entre la coordonnéé destination y de l'amazone : "<<std::endl;
    std::cin>>newY;
    newAmazonPosition = Position(newX,newY);
    while(!this->m_board.isEmpty(newAmazonPosition)){
        std::cout<<"tu t'es trompé sur la coordonée destination de l'amazon "<<std::endl;

        std::cout<<"entre la bonne coordonnéé destination x de l'amazone : "<<std::endl;
        std::cin >>newX ;
        std::cout<<"entre la bonne coordonnéé destination y de l'amazone : "<<std::endl;
        std::cin>>newY;
        newAmazonPosition = Position(newX,newY);
    }

}



void TerminalController::updateArrowPosition(int arrowX, int arrowY, Position& arrowPosition){

    std::cout<<"entre la coordonnéé x de l'arrow : "<<std::endl;
    std::cin >>arrowX;
    std::cout<<"entre la coordonnéé y de l'arrow: "<<std::endl;
    std::cin>>arrowY;
    arrowPosition = Position(arrowX,arrowY);

    while(!this->m_board.isEmpty(arrowPosition)){
        std::cout<<"tu t'es trompé sur la coordonée de l'arrow "<<std::endl;

        std::cout<<"entre la bonne coordonnéé destination x de l'arrow : "<<std::endl;
        std::cin >>arrowX ;
        std::cout<<"entre la bonne coordonnéé destination y de l'arrow : "<<std::endl;
        std::cin>>arrowY;
        arrowPosition = Position(arrowX,arrowY);
    }
}

