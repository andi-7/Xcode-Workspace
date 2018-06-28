//
//  getdht.c
//  BTS-Project1
//
//  Created by Andreas Starzer on 27.06.18.
//  Copyright © 2018 Andreas Starzer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "getdht11.h"

int createSocketandConnect(int port, char* ip){
    //Create Socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Could not create socket!");
    } else {
        printf("Socket created\n");
        server.sin_addr.s_addr = inet_addr(ip);
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
    }
    
    //Try to connect
    if(connect(sock, (struct sockaddr *)&server, sizeof(server))<0){
        fprintf(stderr, "Connection failed!\n");
        exit (EXIT_FAILURE);
    } else {
        printf("Connected\n");
    }
    return sock;
}

void disconnect(int socket){
    shutdown(socket, 2);
}

void sendToServer(int socket, char *ack) {
    send(socket, ack, strlen(ack), 0);
}

void receiveFromServer(int sock, char *data){
    if(recv(sock, data, 15, 0) <0){
        fprintf(stderr, "Receive failed!");
    } else {
    }
}

void convertAndPrint(char *data){
    char *Humid =  malloc(5*sizeof(char));
    char *TempC = malloc(5*sizeof(char));
    char *TempF = malloc(5*sizeof(char));
    
    Humid = strtok(data, ";");
    TempC = strtok(NULL, ";");
    TempF = strtok(NULL, "\0");
    
    printf("\n");
    printf("Luftfeuchtigkeit: %s%%\n", Humid);
    printf("Temperatur: %s°C\n", TempC);
    printf("Temperatur: %s°F\n", TempF);
    printf("\n");
}


int main(int argc, const char * argv[]) {
    if(argc==2) {
        if (strcmp(argv[1], "-h")==0) {
            printf("Help: \n");
            printf("Bitte 1 eingeben und Enter drücken zum Empfangen\n");
            printf("Bitte 2 eingeben und Enter drücken zum Beenden\n");
            return 0;
        }
    }
    
    char *ip = "192.168.43.106";
    int port = 12345;
    int eingabe=0;
    char *daten=malloc(15*sizeof(char));
    int socket1 = createSocketandConnect(port, ip);
    char *ack="ACK";
    int check;
    
    printf("-h für Hilfe\n");
    
    while(eingabe!=2) {
      printf("Option: ");
      check = scanf("%d",&eingabe);
        if(check==0){
            fprintf(stderr, "Falsche Eingabe!\n");
            return 0;
        }
    
        if (eingabe==1) {
            sendToServer(socket1, ack);
            receiveFromServer(socket1, daten);
            convertAndPrint(daten);
        }
    }
    disconnect(socket1);
    return 0;
}
