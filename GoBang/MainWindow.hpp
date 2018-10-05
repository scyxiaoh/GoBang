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
#include <thread>
#include <string.h>
#include "GoBangPlayer.hpp"

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
    std::thread serverThread;
    std::thread clientThread;
    std::unique_ptr<QGraphicsScene> currentScene;

};

#endif /* MainWindow_hpp */
