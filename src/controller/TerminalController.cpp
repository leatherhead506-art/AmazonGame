#include"TerminalController.h"
#include<iostream>


TerminalController::TerminalController(Player& player1,Player& player2):
m_board(Board(player1,player2))
{
    
   
}



Board TerminalController::getBoard()const{
    return this->m_board;
}


void TerminalController::run(){
    while(!this->m_board.isGameEnded()){
        this->update();
    }
    if(this->m_board.getWinner()== PlayerID::Player1){
        std::cout << "le joueur 1 a gagné" << std::endl;
    }
    else{
        std::cout << "le joueur 2 a gagné" << std::endl;
    }
    
}


void TerminalController::update(){
    this->m_board.displayBoard();
    int x_amazon;
    int y_amazon;
    int x_new_position;
    int y_new_position;
    int x_arrow;
    int y_arrow;

    std::cout<<"entre la coordonnéé x de l'amazone : "<<std::endl;
    std::cin >>x_amazon ;
    std::cout<<"entre la coordonnéé y de l'amazone : "<<std::endl;
    std::cin>>y_amazon;
    Position amazonPosition = Position(x_amazon,y_amazon);

    while(!this->m_board.isAmazon(amazonPosition)){
        std::cout<<"tu t'es trompé sur la coordonée de l'amazon "<<std::endl;

        std::cout<<"entre la bonne coordonnéé x de l'amazone : "<<std::endl;
        std::cin >>x_amazon ;
        std::cout<<"entre la bonne coordonnéé y de l'amazone : "<<std::endl;
        std::cin>>y_amazon;
        amazonPosition = Position(x_amazon,y_amazon);
    }






    std::cout<<"entre la coordonnéé destination x de l'amazone : "<<std::endl;
    std::cin >>x_new_position ;
    std::cout<<"entre la coordonnéé destination y de l'amazone : "<<std::endl;
    std::cin>>y_new_position;
    Position newAmazonPosition = Position(x_new_position,y_new_position);
    while(!this->m_board.isEmpty(newAmazonPosition)){
        std::cout<<"tu t'es trompé sur la coordonée destination de l'amazon "<<std::endl;

        std::cout<<"entre la bonne coordonnéé destination x de l'amazone : "<<std::endl;
        std::cin >>x_new_position ;
        std::cout<<"entre la bonne coordonnéé destination y de l'amazone : "<<std::endl;
        std::cin>>y_new_position;
        newAmazonPosition = Position(x_new_position,y_new_position);
    }






    std::cout<<"entre la coordonnéé x de l'arrow : "<<std::endl;
    std::cin >>x_arrow ;
    std::cout<<"entre la coordonnéé y de l'arrow: "<<std::endl;
    std::cin>>y_arrow;
    Position arrowPosition = Position(x_arrow,y_arrow);

    while(!this->m_board.isEmpty(arrowPosition)){
        std::cout<<"tu t'es trompé sur la coordonée de l'arrow "<<std::endl;

        std::cout<<"entre la bonne coordonnéé destination x de l'arrow : "<<std::endl;
        std::cin >>x_arrow ;
        std::cout<<"entre la bonne coordonnéé destination y de l'arrow : "<<std::endl;
        std::cin>>y_arrow;
        arrowPosition = Position(x_arrow,y_arrow);
    }
    
    Amazon amazon = this->m_board.getAmazon(amazonPosition);
    this->m_board.update(amazon,newAmazonPosition,arrowPosition);





}


