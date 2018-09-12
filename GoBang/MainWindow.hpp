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

class MainWindow : public QMainWindow {
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setScene(QGraphicsScene *scene);

private:
    QGraphicsView *view;
    QGraphicsScene *currentScene;
};

#endif /* MainWindow_hpp */
