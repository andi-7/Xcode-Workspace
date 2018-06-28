//
//  Header.h
//  BTS-Project1
//
//  Created by Andreas Starzer on 27.06.18.
//  Copyright © 2018 Andreas Starzer. All rights reserved.
//


#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr

#ifndef Header_h
#define Header_h

//Prototypes
struct sockaddr_in server;
int createSocketandConnect(int port, char* ip);
void disconnect(int socket);
void sendToServer(int socket, char *ack);
void receiveFromServer(int sock, char *data);
void convertAndPrint(char *data);


#endif /* Header_h */
