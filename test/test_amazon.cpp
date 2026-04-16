#include "../src/Position.h"
#include "../src/Board.h"
#include <cassert>
#include <iostream>


Player player1(PlayerID::Player1);
Player player2(PlayerID::Player2);

Amazon amazon1(Position(0,1),player1);
Amazon amazon2(Position(1,0),player2);

Board board(player1,player2);






void testSetPosition(){
    Position newPos(3,3);
    amazon1.setPosition(newPos);
    assert(amazon1.getPosition().getX() == 3);
    assert(amazon1.getPosition().getY() == 3);
    assert(amazon1.getPosition().getX() != 0);
    assert(amazon1.getPosition().getY() != 1);
}


void testAvailablePosition(){

    amazon1.setPosition(Position(0,1));
    assert(amazon1.contains(amazon1.availablePositions(board),Position(0,0))== true);
    assert(amazon1.contains(amazon1.availablePositions(board),Position(0,2))== true);
    assert(amazon1.contains(amazon1.availablePositions(board),Position(0,3))== true);
    assert(amazon1.contains(amazon1.availablePositions(board),Position(1,1))== true);
    assert(amazon1.contains(amazon1.availablePositions(board),Position(2,1))== true);

    assert(amazon1.contains(amazon1.availablePositions(board),Position(1,0))== false);
    assert(amazon1.contains(amazon1.availablePositions(board),Position(2,0))== false);
    assert(amazon1.contains(amazon1.availablePositions(board),Position(3,2))== false);



}



void testCanMoveTo(){

    assert(amazon2.canMoveTo(board,Position(1,1)) == true);
    assert(amazon2.canMoveTo(board,Position(2,1)) == true);
    assert(amazon2.canMoveTo(board,Position(2,2)) == false);
    assert(amazon2.canMoveTo(board,Position(3,3)) == false);
}






int main(){
    testSetPosition();
    testAvailablePosition();
    testCanMoveTo();


    std::cout << "All Amazon tests passed ✅" << std::endl;
    return 0;
}