//
//  GoBangRandomPlayer.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/10/16.
//

#include "GoBangRandomPlayer.hpp"


GoBangMove* GoBangRandomPlayer::chooseMove(GoBangState state) {
    std::vector<GoBangMove*> allPossibleMoves = state.allPossibleMoves(playerId);
    int randomNumer = rand() % allPossibleMoves.size();
    GoBangMove *toReturn = allPossibleMoves[randomNumer];
    
    //free memory of the vector
    for (std::vector<GoBangMove*>::iterator it = allPossibleMoves.begin(); it != allPossibleMoves.end(); ++it){
        if ((*it) != toReturn){
            delete (*it);
        }
    }
    allPossibleMoves.clear();
    allPossibleMoves.shrink_to_fit();
    return toReturn;
}
