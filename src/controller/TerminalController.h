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


private:

Board m_board;

};



#endif