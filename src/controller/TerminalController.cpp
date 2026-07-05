#include"TerminalController.h"
#include<iostream>




TerminalController::TerminalController(Player& player1,Player& player2):
m_board(Board(player1,player2))
{
    
   
}


Position amazonPosition(0,0);

Position newAmazonPosition(0,0);

Position arrowPosition(0,0);


Board TerminalController::getBoard()const{
    return this->m_board;
}








void TerminalController::run(){
    while(!this->m_board.isGameEnded()){
        this->update();
    }
    this->m_board.displayBoard();
    std::cout<< " the game ended "<< std::endl;
    if(this->m_board.getWinner()== PlayerID::Player1){
        std::cout << "le joueur 1 a gagné" << std::endl;
    }
    else{
        std::cout << "le joueur 2 a gagné" << std::endl;
    }
    
}







void TerminalController::update(){
    this->m_board.displayBoard();
    int x_amazon = 0;
    int y_amazon = 0;
    int x_new_position = 0;
    int y_new_position = 0;
    int x_arrow = 0;
    int y_arrow = 0;


    amazonPosition = Position(x_amazon,y_amazon);
    this->selectAmazonPosition(x_amazon,y_amazon,amazonPosition);



    newAmazonPosition = Position(x_new_position,y_new_position);
    this->selectAmazonDestination(x_new_position,y_new_position,newAmazonPosition);



    arrowPosition = Position(x_arrow,y_arrow);
    this->selectArrowPosition(x_arrow,y_arrow,arrowPosition);


    
    Amazon amazon = this->m_board.getAmazon(amazonPosition);
    this->m_board.update(amazon,newAmazonPosition,arrowPosition);


    this->m_board.nextTurn();
    

}







void TerminalController::selectAmazonPosition(int x, int y, Position& amazonPosition){
    std::cout<<"entre la coordonnéé x de l'amazone : "<<std::endl;
    std::cin >>x ;
    std::cout<<"entre la coordonnéé y de l'amazone : "<<std::endl;
    std::cin>>y;
    amazonPosition = Position(x,y);



    while(!this->m_board.isAmazon(amazonPosition)
        || !this->m_board.getAmazonPlayer(this->m_board.getAmazon(amazonPosition),
            this->m_board.getPlayerByTurn())){

        std::cout<<"tu t'es trompé sur la coordonée de l'amazon ou tu as selectionné l'amazone d'un autre joueuer"<<std::endl;

            

        std::cout<<"entre la bonne coordonnéé x de l'amazone : "<<std::endl;
        std::cin >>x;
        std::cout<<"entre la bonne coordonnéé y de l'amazone : "<<std::endl;
        std::cin>>y;
        amazonPosition = Position(x,y);
    



    }

}








void TerminalController::selectAmazonDestination(int newX, int newY, Position& newAmazonPosition){



    std::cout<<"entre la coordonnéé destination x de l'amazone : "<<std::endl;
    std::cin >>newX ;
    std::cout<<"entre la coordonnéé destination y de l'amazone : "<<std::endl;
    std::cin>>newY;
    newAmazonPosition = Position(newX,newY);
    while(!this->m_board.isEmpty(newAmazonPosition) || 
    !this->m_board.getAmazon(amazonPosition).canMoveTo(this->m_board,newAmazonPosition)){

        std::cout<<"tu t'es trompé sur la coordonée destination de l'amazon "<<std::endl;

        std::cout<<"entre la bonne coordonnéé destination x de l'amazone : "<<std::endl;
        std::cin >>newX ;
        std::cout<<"entre la bonne coordonnéé destination y de l'amazone : "<<std::endl;
        std::cin>>newY;
        newAmazonPosition = Position(newX,newY);
    }

}







void TerminalController::selectArrowPosition(int arrowX, int arrowY, Position& arrowPosition){
    this->m_board.setPiece(Piece::EMPTY,amazonPosition);
    std::cout<<"entre la coordonnéé x de l'arrow : "<<std::endl;
    std::cin >>arrowX;
    std::cout<<"entre la coordonnéé y de l'arrow: "<<std::endl;
    std::cin>>arrowY;
    arrowPosition = Position(arrowX,arrowY);

    while(!this->m_board.isEmpty(arrowPosition)){
        std::cout<<"tu t'es trompé sur la coordonée de l'arrow "<<std::endl;

        std::cout<<"entre la bonne coordonnéé destination x de l'arrow : "<<std::endl;
        std::cin >>arrowX ;
        std::cout<<"entre la bonne coordonnéé destination y de l'arrow : "<<std::endl;
        std::cin>>arrowY;
        arrowPosition = Position(arrowX,arrowY);
    }
}

