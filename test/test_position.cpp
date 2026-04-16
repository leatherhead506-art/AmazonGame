#include "../src/Position.h"
#include "../src/Board.h"
#include <cassert>
#include <iostream>





void testConstructor() {
    Position p(3, 4);
    assert(p.getX() == 3);
    assert(p.getY() == 4);
}




void testSetPosition() {
    Position p(0, 0);
    p.setPosition(5, 6);
    assert(p.getX() == 5);
    assert(p.getY() == 6);
}



void testOutOfBound() {
    Player p1(PlayerID::Player1);
    Player p2(PlayerID::Player2);
    Board board(p1, p2);

    Position inside(3, 3);
    Position outside(-1, 10);

    assert(inside.isOutOfBound(board) == false);
    assert(outside.isOutOfBound(board) == true);
}




int main() {

    testConstructor();
    testSetPosition();
    testOutOfBound();

    std::cout << "All Position tests passed ✅" << std::endl;

    return 0;
}
