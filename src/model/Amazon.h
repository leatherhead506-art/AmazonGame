#ifndef AMAZON_H
#define AMAZON_H

#include<vector>

#include "Piece.h"
#include "player/Player.h"
#include "Position.h"



class Amazon{

public:

    Amazon(const Position& position,const Player& player);

    bool canMoveTo(const Board& board, const Position& position);

    std::vector<Position> availablePositions(const Board& board)const;

    Position getPosition()const;

    void setPosition(const Position& position);

    bool contains(const std::vector<Position>& positionList, const Position& position);

    Player getPlayer()const;

    bool isEqual(Amazon& amazon);



private:

    Position m_startingPosition;
    
    const Player m_player;

};


#endif