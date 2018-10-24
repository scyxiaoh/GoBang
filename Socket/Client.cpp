//
//  Client.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/21.
//

#include "Client.hpp"


Client::Client(GoBangPlayer *p, GoBangGame *g) {
    player = p;
    game = g;
    userMoveNeeded = false;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote_addr.sin_port = htons(8000);
}

Client::~Client() { 
    delete player;
    delete game;
}

int Client::getlocalPlayerId() { 
    return player->playerId;
}

bool Client::connected() {
    if ((socketfd = socket(PF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket error");
        return false;
    }
    if (connect(socketfd, (struct sockaddr*)&remote_addr, sizeof(struct sockaddr)) < 0) {
        perror("connect error");
        return false;
    }
    
    printf("connected to server\n");
    
    return true;
}

void Client::run() {
    if (connected()){
        clientLoop();
    }
}

void Client::clientLoop() {
    
    while (true) {
        if((len = read(socketfd, buffer, 1024)) > 0){
            buffer[len] = '\0';
            std::cout << "client receive message: " << buffer << std::endl;
            processMessage(QString(buffer));
        }
    }
    
    close(socketfd);
}


std::thread Client::thread() { 
    return std::thread(&Client::run, this);
}

void Client::processMessage(QString message) {

    if (message == "") return;
    
    QStringList segments = message.split('|');
    if (segments.size() > 1) {
        for (int i = 0; i < segments.size(); i++) {
            processMessage(segments.at(i));
        }
        return;
    }
    
    if (message.startsWith("PLAY")){
        //Message format: PLAY int0
        //int0 -> playerId which is requested to make a move
        QStringList components = message.split(' ');
        if (components.size() < 2) {
            perror("ERROR: Client received a invalid PLAY message.\n");
            exit(EXIT_FAILURE);
        }
        
        if (components.at(1).toInt() == player->playerId){
            playMove(player->chooseMove(game->state));
        }
    }
    else if (message.startsWith("GAMEOVER")){
        
    }
    else {
        //Message format: int0 int1 int2
        //int0 -> x of move's coord
        //int1 -> y of move's coord
        //int2 -> playerId of the move's belonging
        
        GoBangMove *move = game->parseMove(message);
        if (move == nullptr) exit(EXIT_FAILURE);    //if the move message is invalid, exit
        else {
            game->processMove(*move);
        }
    }
}


void Client::playMove(GoBangMove *decision) {
    if (decision == nullptr){
        if (game->guiHandler != nullptr){
            //let local player decide move
            userMoveNeeded = true;
        }
        else {
            //wait for opponent's movement
        }
    }
    else {
        //translate the move into a string
        std::string str = decision->toString() + "|";
        char *cstr = new char [str.size() + 1];
        strcpy(cstr, str.c_str());
        
        //send the move decision to the server
        if((len = send(socketfd, cstr, strlen(cstr),0)) < 0){
            perror("ERROR: Unable to write move to server.");
        }
        
        delete[] cstr;
    }
}
