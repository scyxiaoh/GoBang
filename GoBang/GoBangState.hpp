//
//  GoBangBoard.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/12.
//

#ifndef GoBangBoard_hpp
#define GoBangBoard_hpp

#include <stdio.h>
#include "Coord/Coord.hpp"
#include "GoBangMove.hpp"

class GoBangState{
public:
    static int size;
    int longestRowWhite;
    int longestRowBlack;
    GoBangState(const int pSize);
    GoBangState(GoBangState *toClone);
    ~GoBangState();
    inline Coord *get(int x, int y){
        return (this->coords + x*this->size + y);
    };
    bool isValidMove(int x, int y);
    void processMove(GoBangMove m);
    std::vector<GoBangMove*> allPossibleMoves(int playerId);
    GoBangMove *randomMove(int playerId);
private:
    Coord *coords;
};
#endif /* GoBangBoard_hpp */
