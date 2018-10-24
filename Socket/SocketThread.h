//
//  SocketThread.h
//  GoBang
//
//  Created by Kevin Sun on 2018-10-23.
//

#ifndef SocketThread_h
#define SocketThread_h

#include <QThread>
#include "Socket.hpp"
class SocketThread : public QThread {
    Q_OBJECT
public:
    SocketThread(Socket *s, QObject *parent = nullptr) : QThread(parent){
        socket = s;
    }
    void run() override {
        socket->run();
    }
private:
    Socket *socket;
};

#endif /* SocketThread_h */
