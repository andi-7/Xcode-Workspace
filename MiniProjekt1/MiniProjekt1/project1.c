//
//  main.c
//  MiniProjekt1
//
//  Created by Andreas Starzer on 25.05.18.
//  Copyright © 2018 Andreas Starzer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "project1.h"

//----------Function prototypes----------
void createList(void);


//----------Functions----------

//Create empty list
void createList(){
  HEADER *root = malloc(sizeof(ELEM));
    
    //Define first Element
    root->first->data=NULL;
    root->first->next=NULL;
    root->first->prev=NULL;
    
    //Define last Element
    root->last->data=NULL;
    root->last->next=NULL;
    root->last->prev=NULL;
}

//Append new Element first
void appendFirstElem(DATA *data){
    
}

//Append new Element last
void appendLastElem(DATA *data){
    
}

//----------Main----------
int main(int argc, const char * argv[]) {
    
    return 0;
}
