//
//  MainWindow.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/12.
//

#include <iostream>
#include <string>
#include "MainWindow.hpp"
#include "Scene/TitleScene.hpp"
#include "Scene/GameScene.hpp"
#include "GoBangGame.hpp"
#include "Client.hpp"
#include "Server.hpp"
	
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
    
    //test server
    Server *server = new Server();
    
    serverThread = server->thread();
    
    Client *client = new Client(p2, game);
    clientThread = client->thread();
    clientThread.join();
    
    setScene(new GameScene(client));
}



