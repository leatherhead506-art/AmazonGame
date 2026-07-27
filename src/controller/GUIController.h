#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include<vector>
#include <SFML/Graphics.hpp>
#include "../model/player/Player.h"
#include "../model/board/Board.h"


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
};

#endif