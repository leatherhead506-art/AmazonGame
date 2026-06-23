#include "Amazon.h"
#include "Direction.h"
#include "board/Board.h"
#include<iostream>  

Amazon::Amazon(const Position& position,const Player& player):
m_startingPosition(position),m_player(player)
{

}




bool Amazon::canMoveTo(const Board& board, const Position& position){
    return this->contains(availablePositions(board),position);
}



bool Amazon::contains(const std::vector<Position>& positionList, const Position& position){
    for(size_t indexPos = 0;indexPos < positionList.size();indexPos++){
        if(positionList.at(indexPos).getX() == position.getX()
            && positionList.at(indexPos).getY() == position.getY()){
            return true;
        }
    }
    return false;
}




std::vector<Position> Amazon::availablePositions(const Board& board)const{
    std::vector<Position> positions;
    for(const Position &direction : Direction::getDirections()){
        Position newDirection = direction;
        int newX = getPosition().getX()+ newDirection.getX();
        int newY = getPosition().getY()+ newDirection.getY();
        Position newPos(newX,newY);
        while(!board.isOutOfBound(*this) && board.isEmpty(newPos)){
            positions.push_back(newPos);
            newX += newDirection.getX();
            newY += newDirection.getY();
            newPos.setPosition(newX,newY);
        }
    }

    return positions;
}








void Amazon::setPosition(const Position& position){
    this->m_startingPosition = position;
}



Player Amazon::getPlayer()const{
    return this->m_player;
}

Position Amazon::getPosition()const{
    return this->m_startingPosition;
}


bool Amazon::isEqual(Amazon& amazon){
    if(this->getPosition().getX() == amazon.getPosition().getX()
    &&this->getPosition().getY() == amazon.getPosition().getY()){
        return true;
    }
    return false;
}