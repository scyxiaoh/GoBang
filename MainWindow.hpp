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

namespace Ui {
    class MainWindow;
}

class MainWindow : QMainWindow {
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnAbout_clicked();
    void on_btnComputer_clicked();
    void on_btnNet_clicked();
    void on_btnPeople_clicked();
    
private:
    Ui::MainWindow *ui;
};

#endif /* MainWindow_hpp */
