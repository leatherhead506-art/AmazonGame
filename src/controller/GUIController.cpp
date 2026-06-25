#include <SFML/Graphics.hpp>
#include "GUIController.h"

GuiController::GuiController(Player& player1,Player& player2, Board& board)
{
    board = Board(player1,player2);
   
}


void GuiController::run(){

}