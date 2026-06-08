#include "Position.h"
#include "Board.h"

Position::Position(int x,int y):m_x{x},m_y{y}{

}

int Position::getX()const{
    return this->m_x;
}

int Position::getY()const{
    return this->m_y;
}

bool Position::isOutOfBound(const Board& board){
    if( this->getX()< 0 || this->getX()>= board.ROWS
        || this->getY() < 0 || this->getY()>= board.COLUMNS){
        return true;
    }
    return false;
}

void Position::setPosition(int x,int y){
    this->m_x = x;
    this->m_y = y;
}

