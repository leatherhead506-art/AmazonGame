#include "../src/model/Position.h"
#include "../src/model/board/Board.h"
#include <cassert>
#include <iostream>


Player p1(PlayerID::Player1);
Player p2(PlayerID::Player2);
Board board(p1, p2);



void testSetAmazonPosition(){
    
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
    
}




void testIsGameEnded(){

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


    std::cout << "All Amazon tests passed ✅" << std::endl;
    std::cout<< board.toString(8,8) << std::endl;



    

    

    return 0;
}
