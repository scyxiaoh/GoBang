//
//  GoBangMove.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/13.
//

#include "GoBangMove.hpp"


GoBangMove::GoBangMove(Coord *place, int player) {
    end = place;
    playerId = player;
}

/**
 return this move result to a certain QGraphicsItem to be drawn
 **/
QGraphicsRectItem *GoBangMove::parseItem() { 
    QImage pieceImage;
    if (playerId == 0) {
        pieceImage = Resources::Image::blackPiece();
    }
    else {
        pieceImage = Resources::Image::whitePiece();
    }
    QGraphicsRectItem* rectItem = new QGraphicsRectItem(0, 0, 32, 32);
    rectItem->setBrush(QBrush(pieceImage.scaled(32, 32)));
    rectItem->setPen(QColor(0,0,0,0));
    rectItem->setPos((qreal)end->x * 32 + 60, (qreal)end->y * 32 + 60);
    return rectItem;
}

void GoBangMove::process() {
    end->setOccupancy(playerId);
}

std::string GoBangMove::toString() {
    return std::to_string(this->end->x) + " " + std::to_string(this->end->y) + " " + std::to_string(this->playerId);
}




