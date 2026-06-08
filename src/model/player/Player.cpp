#include "Player.h"


Player::Player(PlayerID playerID):m_playerID{playerID}{}

PlayerID Player::getPlayerID()const{
    return this->m_playerID;
}

