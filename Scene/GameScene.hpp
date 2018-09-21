//
//  GameScene.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/12.
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <stdio.h>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "Gobang/Client.hpp"

class GameScene : public QGraphicsScene {
public:
    GameScene(Client *c);
    ~GameScene();
    
private:
    QGraphicsRectItem *potentialPiece;
    Client *client;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif /* GameScene_hpp */
