
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
    m_window.display();


}


void GuiController::drawBoard(){
    for(int row = 0; row < this->m_board.ROWS; row++){
        bool isBeige = true;
        for(int column = 0; column < this->m_board.COLUMNS;column++){
            sf::RectangleShape rectangle(sf::Vector2f(CELL_SIZE,CELL_SIZE));
            rectangle.setPosition(sf::Vector2f(row * CELL_SIZE, column * CELL_SIZE));
            if(isBeige){
                rectangle.setFillColor(sf::Color(240,217,181));
                isBeige = false;
            }
            else{
                rectangle.setFillColor(sf::Color(255,255,255));
                isBeige = true;
            }
        }
        if(isBeige){
            isBeige = false;
        }
        else{
            isBeige = true;
        }
    }
}




void GuiController::drawPieces(){
    
}