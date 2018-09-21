//
//  MainWindow.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/12.
//

#include <iostream>
#include "MainWindow.hpp"
#include "Scene/TitleScene.hpp"
#include "Scene/GameScene.hpp"
#include "GoBangGame.hpp"
#include "Client.hpp"
	
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
{
    this->setFixedSize(800,600);
    view = new QGraphicsView(this);
    this->setCentralWidget(view);

    setScene(new TitleScene(this));
    
}

MainWindow::~MainWindow(){
    currentScene.release();
    delete view;
}

void MainWindow::setScene(QGraphicsScene *scene) {
    currentScene.reset(scene);
    view->setScene(currentScene.get());
}

void MainWindow::startGame() {
    GoBangPlayer *p1 = new GoBangPlayer(0);
    GoBangPlayer *p2 = new GoBangPlayer(1);
    GoBangGame *game = new GoBangGame(p1, p2);
    Client *client = new Client(p2, game);
    setScene(new GameScene(client));
}



