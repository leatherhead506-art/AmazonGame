#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include<string>

#include "../Piece.h"
#include "../player/Player.h"
#include "../Amazon.h"

class Position;

class Board{

public:

    static const int ROWS = 8;
    static const int COLUMNS = 8;

    Board(const Player& player1,const Player& player2);

    void init();
    
    std::vector<Position>defaultAmazonPositions();

    bool isOutOfBound(const Amazon& amazon)const;

    bool isGameEnded()const;

    PlayerID getWinner()const;

    std::vector<Amazon> getPlayerAmazons(const Player& player)const;

    void setAmazonPosition(Amazon& amazon,const Position& position);

    void moveAmazon(Amazon& amazon, const Position& position);  
    
    void throwArrow(Amazon& amazon,const Position& position);

    void setPiece(Piece piece, const Position& position);

    bool isEmpty(const Position& position)const;

    void update(Amazon& amazon, Position& newAmazonPos, Position& arrowPos);

    int getTurnCount()const;

    void nextTurn();

    Player& getPlayerByTurn();

    bool getAmazonPlayer(Amazon& amazon, Player& player);

    bool isAmazon(Position& position);

    Amazon& getAmazon(Position& position);


    std::string displayPiece(const Position& position);


    std::string toString(int row, int column);

    void displayBoard();

    Piece getPiece(const Position& position) const;

private:

    std::vector<Amazon> m_amazon_list;

    Piece m_pieces[ROWS][COLUMNS];

    int m_count_turn = 0;

    Player m_player1;

    Player m_player2;

    static const int PLAYER_AMAZON_NUMBER = 4;
    

};


#endif