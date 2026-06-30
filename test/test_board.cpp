#include "../src/model/Position.h"
#include "../src/model/board/Board.h"
#include <cassert>
#include <iostream>


Player p1(PlayerID::Player1);
Player p2(PlayerID::Player2);
Board board(p1, p2);



void testSetAmazonPosition(){
    
    board.setPiece(Piece::AMAZON,Position(1,1));
    assert(board.isEmpty(Position(1,1)) == false);
}




void testSetPiece(){
    board.setPiece(Piece::ARROW,Position(0,4));
    assert(board.isEmpty(Position(0,4)) == false);
    board.setPiece(Piece::AMAZON,Position(1,1));
    assert(board.isEmpty(Position(1,1)) == false);
    board.setPiece(Piece::EMPTY,Position(1,1));
    assert(board.isEmpty(Position(1,1)) == true);
}



void testIsOutOfBound(){
    
    assert(board.isOutOfBound(Amazon(Position(9,1),Player(PlayerID::Player1)))==true);
    assert(board.isOutOfBound(Amazon(Position(-1,1),Player(PlayerID::Player1)))==true);
    assert(board.isOutOfBound(Amazon(Position(7,1),Player(PlayerID::Player1)))==false);
}






void testIsEmpty(){
    board.setPiece(Piece::ARROW,Position(0,4));
    assert(board.isEmpty(Position(0,4)) == false);
    board.setPiece(Piece::AMAZON,Position(1,1));
    assert(board.isEmpty(Position(1,1)) == false);
    board.setPiece(Piece::EMPTY,Position(1,1));
    assert(board.isEmpty(Position(1,1)) == true);
}




int main(){

    testSetPiece();
    testIsEmpty();

    testIsOutOfBound();
    std::cout << "All Amazon tests passed ✅" << std::endl;
    std::cout<< board.toString(8,8) << std::endl;



    

    

    return 0;
}
