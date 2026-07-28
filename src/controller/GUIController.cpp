
#include "GUIController.h"
#include <iostream>
GuiController::GuiController(Player& player1,Player& player2):
m_board(Board(player1,player2)),
m_window(sf::VideoMode(800,800),"Amazon Game"),
m_state(SelectionState::SelectingAmazon)
{
    
   
}


void GuiController::run(){
    while(m_window.isOpen() && !this->m_board.isGameEnded()){
        this->update();
        this->displayGui();
        
        
    }
    std::cout<< " the game ended "<< std::endl;
    if(this->m_board.getWinner()== PlayerID::Player1){
        std::cout << "le joueur 1 a gagné" << std::endl;
    }
    else{
        std::cout << "le joueur 2 a gagné" << std::endl;
    }
}





void GuiController::update(){
    sf::Event event;
    Position clickedPosition;

    while(m_window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            m_window.close();

        }
        if(event.type == sf::Event::MouseButtonPressed){

            if(event.mouseButton.button == sf::Mouse::Left){
                int pixelX = event.mouseButton.x;
                int pixelY = event.mouseButton.y;
                clickedPosition = Position(pixelY/ CELL_SIZE, pixelX/CELL_SIZE);
            }




            switch (m_state){

            case SelectionState::SelectingAmazon:

                std::cout<<"Click recu - > Position ("<< clickedPosition.getX()<< " , "
                << clickedPosition.getY()<< " )"<<std::endl;

                if(m_board.isAmazon(clickedPosition)){
                    if(m_board.getAmazonPlayer(this->m_board.getAmazon(clickedPosition),
                    this->m_board.getPlayerByTurn())){

                    m_selectedAmazonPos = clickedPosition;
                    this->m_state = SelectionState::SelectingDestination;

                    }
                }
                
                break;







            case SelectionState::SelectingDestination:
                if(m_board.isEmpty(clickedPosition) &&
                 m_board.getAmazon(m_selectedAmazonPos).canMoveTo(m_board, clickedPosition)){
                    m_selectedDesinationPos = clickedPosition;
                    this->m_state = SelectionState::SelectingArrow;
                }
            
                break;





            case SelectionState::SelectingArrow:
                if(m_board.isEmpty(clickedPosition) ){
                    m_selectedArrowPos = clickedPosition;
                    m_board.update(m_board.getAmazon(m_selectedAmazonPos), m_selectedDesinationPos, m_selectedArrowPos);
                    m_board.nextTurn();
                    this->m_state = SelectionState::SelectingAmazon;
                }
                
            
            
                break;
            


            default:
                break;


            }
        }
    }


}




void GuiController::displayGui(){

    m_window.clear();

    this->drawBoard();
    this->drawPieces();

    m_window.display();


}


void GuiController::drawBoard(){


    for(int row = 0; row < this->m_board.ROWS; row++){

        for(int column = 0; column < this->m_board.COLUMNS;column++){

            sf::RectangleShape rectangle(sf::Vector2f(CELL_SIZE,CELL_SIZE));
            rectangle.setPosition(sf::Vector2f(column * CELL_SIZE, row * CELL_SIZE));
            
            if((row + column) % 2 == 0){
                rectangle.setFillColor(sf::Color(181,136,99));

            }
            else{
                rectangle.setFillColor(sf::Color(255,255,255));
            
            }
            m_window.draw(rectangle);
        }
    }
}




void GuiController::drawPieces(){
    for(int row = 0; row < this->m_board.ROWS ; row ++){
        for(int column = 0; column < this->m_board.COLUMNS; column ++){

            Position current_pos(row,column);
            Piece piece = this->m_board.getPiece(current_pos);

            if(piece == Piece::AMAZON){

                sf::CircleShape amazon(40.f);
                PlayerID player = this->m_board.getAmazon(current_pos).getPlayer().getPlayerID();

                if(player == PlayerID::Player1){
                    amazon.setFillColor(sf::Color(0,0,255));
                }

                else{
                    amazon.setFillColor(sf::Color(255,0,0));
                }
                amazon.setPosition(sf::Vector2f(column * CELL_SIZE + 10, row* CELL_SIZE+10));
                m_window.draw(amazon);

            }
            else if(piece == Piece::ARROW){
                sf::CircleShape arrow(40.f,3);
                arrow.setFillColor(sf::Color(0,0,0));
                arrow.setPosition(sf::Vector2f(column* CELL_SIZE +10,row * CELL_SIZE+10));
                m_window.draw(arrow);
            }
        }
    }
}