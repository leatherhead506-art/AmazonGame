#include <SFML/Graphics.hpp>
#include "GUIController.h"

GuiController::GuiController(Player& player1,Player& player2):
m_board(Board(player1,player2))
{
    
   
}


void GuiController::run(){

}





void GuiController::update(){

}

void GuiController::displayGui(){

    sf::RenderWindow window(sf::VideoMode(800,800),"Amazon Game");
    
    while(window.isOpen()){

        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::MouseButtonPressed){

            }
        }
        window.clear();
        window.display();
    }

}
