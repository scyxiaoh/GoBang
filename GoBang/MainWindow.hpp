//
//  MainWindow.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/12.
//

#ifndef MainWindow_hpp
#define MainWindow_hpp
#include <QMainWindow>
#include <stdio.h>
#include <QGraphicsView>
#include <string.h>
#include "GoBangPlayer.hpp"
#include "Socket/SocketThread.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setScene(QGraphicsScene *scene);
public slots:
    void startGame();
    
private:
    QGraphicsView *view;
    SocketThread *serverThread;
    SocketThread *clientThread[2];
    std::unique_ptr<QGraphicsScene> currentScene;

};

#endif /* MainWindow_hpp */
