
#include <SFML/Graphics.hpp>
#include "controller/TerminalController.h"
#include "controller/GUIController.h"



int main()
{
    Player player1 = Player(PlayerID::Player1);
    Player player2 = Player(PlayerID::Player2);
    
    TerminalController terminalGame = TerminalController(player1,player2);
    terminalGame.run();
    return 0;
}