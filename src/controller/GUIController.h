#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include<vector>
#include "../model/player/Player.h"
#include "../model/board/Board.h"


class GuiController{

public:

    GuiController(Player& player1, Player& player2, Board& board);



    void run();




private:


};

#endif