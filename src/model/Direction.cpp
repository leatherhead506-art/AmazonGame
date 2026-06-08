#include "Direction.h"

std::vector<Position> Direction::getDirections(){
    std::vector<Position> positions;
    for(int i = -1 ;i <= 1;i++){
        for(int j = -1 ;j <= 1;j++){

            if(i == 0 && j == 0){
                continue;
            }
            Position curPos(i,j);
            positions.push_back(curPos);

        }
    }
    return positions;
}