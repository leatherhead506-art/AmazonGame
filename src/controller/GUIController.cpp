
#include "GUIController.h"

GuiController::GuiController(Player& player1,Player& player2):
m_board(Board(player1,player2)),
m_window(sf::VideoMode(800,800),"Amazon Game")
{
    
   
}


void GuiController::run(){
    while(m_window.isOpen()){
        this->update();
        this->displayGui();
        
        
    }
}





void GuiController::update(){
    sf::Event event;
    while(m_window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            m_window.close();

        }
        if(event.type == sf::Event::MouseButtonPressed){

        }
    }

}




void GuiController::displayGui(){

    m_window.clear();
    //dessiner le plateau, les amazones, les flèches...
    this->drawBoard();
    this->drawPieces();
    m_window.display();


}


void GuiController::drawBoard(){


    for(int row = 0; row < this->m_board.ROWS; row++){

        for(int column = 0; column < this->m_board.COLUMNS;column++){

            sf::RectangleShape rectangle(sf::Vector2f(CELL_SIZE,CELL_SIZE));
            rectangle.setPosition(sf::Vector2f(row * CELL_SIZE, column * CELL_SIZE));
            
            if((row + column) % 2 == 0){
                rectangle.setFillColor(sf::Color(181,136,99));

            }
            else{
                rectangle.setFillColor(sf::Color(255,255,255));
            
            }
            m_window.draw(rectangle);
        }
    }
}




void GuiController::drawPieces(){
    for(int row = 0; row < this->m_board.ROWS ; row ++){
        for(int column = 0; column < this->m_board.COLUMNS; column ++){

            Position current_pos(row,column);
            Piece piece = this->m_board.getPiece(current_pos);

            if(piece == Piece::AMAZON){

                sf::CircleShape amazon(40.f);
                PlayerID player = this->m_board.getAmazon(current_pos).getPlayer().getPlayerID();

                if(player == PlayerID::Player1){
                    amazon.setFillColor(sf::Color(0,0,255));
                }

                else{
                    amazon.setFillColor(sf::Color(255,0,0));
                }
                amazon.setPosition(sf::Vector2f(column * CELL_SIZE + 10, row* CELL_SIZE+10));
                m_window.draw(amazon);

            }
            else if(piece == Piece::ARROW){
                sf::CircleShape arrow(40.f,3);
                arrow.setFillColor(sf::Color(0,0,0));
                arrow.setPosition(sf::Vector2f(column* CELL_SIZE +10,row * CELL_SIZE+10));
                m_window.draw(arrow);
            }
        }
    }
}