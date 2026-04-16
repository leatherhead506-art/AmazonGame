#ifndef POSITION_H
#define POSITION_H

class Board;


class Position{

public:

    Position(int x, int y);
    
    int getX()const;
    int getY()const;
    void setPosition(int x,int y);
    bool isOutOfBound(const Board& board);
    
private:
    int m_x;
    int m_y;


};


#endif