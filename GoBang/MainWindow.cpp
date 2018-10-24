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
#include "Socket/Client.hpp"
#include "Socket/Server.hpp"
#include "GoBangRandomPlayer.hpp"
	
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
    GoBangPlayer *p2 = new GoBangRandomPlayer(1);
    GoBangGame *game1 = new GoBangGame();
    GoBangGame *game2 = new GoBangGame();
    
    //test server
    Server *server = new Server();
    serverThread = new SocketThread(server, this);
    
    Client *client1 = new Client(p1, game1);
    Client *client2 = new Client(p2, game2);
    clientThread[0] = new SocketThread(client1, this);
    clientThread[1] = new SocketThread(client2, this);
    GameScene *gScene = new GameScene(client1);

    serverThread->start();
    clientThread[0]->start();
    clientThread[1]->start();
    
    setScene(gScene);
}





