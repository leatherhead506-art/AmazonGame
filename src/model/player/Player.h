#ifndef PLAYER_H
#define PLAYER_H

enum class PlayerID{
    NoPlayer = 0,
    Player1 = 1,
    Player2 = 2
};

class Player{
public:
    Player(PlayerID playerID);
    PlayerID getPlayerID()const;
    

private:
    PlayerID m_playerID;

};


#endif