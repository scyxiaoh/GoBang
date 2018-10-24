//
//  GoBangMove.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/13.
//

#ifndef GoBangMove_hpp
#define GoBangMove_hpp

#include <stdio.h>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "Coord/Coord.hpp"
#include "GoBang/Resources.hpp"


class GoBangMove {
public:
    GoBangMove(Coord *place, int player);
    Coord *end;
    QGraphicsRectItem* parseItem();
    void process();
    std::string toString();
private:
    int playerId;
};

#endif /* GoBangMove_hpp */
