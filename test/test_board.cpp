#include "../src/Position.h"
#include "../src/Board.h"
#include <cassert>
#include <iostream>











int main(){

    Player p1(PlayerID::Player1);
    Player p2(PlayerID::Player2);
    Board board(p1, p2);

    std::cout<< board.toString(8,8) << std::endl;
    Amazon amazonTest(Position(0,2),p1);
    Position newPos(0,3);
    Position arrowPos(0,4);
    board.update(amazonTest,newPos,arrowPos);

    std::cout<< board.toString(8,8) << std::endl;

    return 0;
}
