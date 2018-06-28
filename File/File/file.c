//
//  main.c
//  File
//
//  Created by Andreas Starzer on 21.06.18.
//  Copyright © 2018 Andreas Starzer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "file.h"

int anzahl;

DATA *readfile(char *filename){
    FILE *fp= fopen(filename, "r");
    DATA *datensätze;
    int i;
    
    if(!fp) {
        printf("Datei konnte nicht geöffnet werden");
        return NULL;
    }
    
    
    fscanf(fp, "%d\n", &anzahl);
    datensätze = malloc(anzahl*sizeof(DATA));
    
    for(i=0;i<=anzahl;i++){
        fscanf(fp, "%d;%s\n", &datensätze[i].temperature, datensätze[i].ort);
    }
    
    fclose(fp);
    return datensätze;
    
}

void printdata(DATA *p){
    int i;
    
    for (i=0;i<=anzahl; i++){
        printf("%d;%s", p[i].temperature, p[i].ort);
    }
}


int main(int argc, const char * argv[]) {

    char file[100]="/Users/andi/Xcode-Workspace/File/File/test.txt";
    
    DATA *daten = readfile(file);
    printdata(daten);
    
    DATA* test = malloc(sizeof(DATA));
    test->ort[0] = 'a';
    strcpy(test->ort, "hallo");
    
    char* ptr = test->ort;
    
   
    DATA* test1;
 
    
    
    return 0;
}
