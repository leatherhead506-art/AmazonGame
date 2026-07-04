#ifndef TERMINALCONTROLLER_H
#define TERMINALCONTROLLER_H

#include "../model/board/Board.h"
#include "../model/player/Player.h"


class TerminalController{

public:

TerminalController( Player& player1, Player& player2);

void update();

void run();

Board getBoard()const;

void getAmazonPosition(int x, int y, Position& amazonPosition);

void updateAmazonPosition(int newX, int newY,Position& newAmazonPosition);

void updateArrowPosition(int arrowX, int arrowY, Position& arrowPosition);

private:

Board m_board;

};



#endif