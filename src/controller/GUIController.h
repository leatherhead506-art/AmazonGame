#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include<vector>
#include <SFML/Graphics.hpp>
#include "../model/player/Player.h"
#include "../model/board/Board.h"
#include "../model/Position.h"


enum class SelectionState{

    SelectingAmazon,
    SelectingDestination,
    SelectingArrow

};




class GuiController{

public:

    GuiController(Player& player1, Player& player2);

    void run();

    void displayGui();

    void update();

    void drawBoard();

    void drawPieces();

private:

    Board m_board;
    sf::RenderWindow m_window;
    static const int CELL_SIZE = 100;
    SelectionState m_state;
    Position m_selectedAmazonPos;
    Position m_selectedDesinationPos;
    Position m_selectedArrowPos;
};






#endif