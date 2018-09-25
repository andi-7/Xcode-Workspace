//
//  project1.c
//  MiniProjekt1 for SWE2
//
//  Created by Andreas Starzer on 25.05.18.
//  Copyright © 2018 Andreas Starzer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"


//----------------------------Functions----------------------------
//Create empty list header
HEADER* createList(){
  
    HEADER *list = malloc(sizeof(ELEM));
    
    list->first=NULL;
    list->last=NULL;
    list->len=0;
    
    return list;
}

//Eine Funktion für "vorne einfügen", "hinten einfügen", "an belibiger stelle einfügen"

void insertElementFront(HEADER *list, int data){
    if(list==NULL) return;
    
    ELEM *newElement = malloc(sizeof(ELEM));
    if(list->len==0){
        list->first=newElement;
        list->last=newElement;
        newElement->next=NULL;
        newElement->prev=NULL;
        newElement->data=data;
    } else if(list->len>=1){
        list->first->prev=newElement;
        newElement->next=list->first;
        newElement->prev=NULL;
        list->first=newElement;
    }
}

void insertElementLast (HEADER *list, int data){
     if(list==NULL) return;
    
    ELEM *newElement = malloc(sizeof(ELEM));
    if(list->len==0){
        list->first=newElement;
        list->last=newElement;
        newElement->next=NULL;
        newElement->prev=NULL;
        newElement->data=data;
    } else if(list->len>=1){
        list->last->next=newElement;
        newElement->prev=list->last;
        newElement->next=NULL;
        list->last=newElement;
    }
}


/*
//Create new Element (first Element of List)
void createNewElem(HEADER *list, ELEM *newElem, int data){
   
    //List is still empty
    if(list->len==0) {
        list->first=newElem;
        list->last=newElem;
        newElem->next=NULL;
        newElem->prev=NULL;
        newElem->data=data;
        list->len+=1;
    } else {
        //List is not empty
        printf("List is not empty! Use appendFirstElem() or appendLastElem()");
    }
}

//Append new Element in front position
void appendFrontElem(HEADER *list, ELEM *newElem, ELEM *prevElem, int data){
    
    //If List is empty
    if(list->len<1) {
        printf("List is empty! Use createNewElem()");
    }
    else {
    //List already has an element
    list->first=newElem;
    newElem->next=NULL;
    newElem->prev=prevElem;
    prevElem->next=newElem;
    newElem->data=data;
    list->len+=1;
    }
}
*/



//Prints the list from last to first (left to right)
void printList(HEADER *list){
    
    //Help pointer
    ELEM *helpPtr=malloc(sizeof(ELEM));
    int i;
    
    helpPtr=list->last;
    
    for(i=1; i<=list->len; i++) {
        printf("%d ", helpPtr->data);
        helpPtr=helpPtr->next;
    }
}

/*
//Search an element in the list and returns the whole element
ELEM *search(HEADER *list, char *key){
    
    if (list==NULL)
        return NULL;
    
    if(list->len==0)
        return NULL;
    
    ELEM *helpPtr=malloc(sizeof(ELEM));
    int i;
    
    helpPtr=list->first;
    
    for(i=0; i<=list->len; i++) {
        if(strcmp(helpPtr->data->zeichen, key)) {
            break;
        } else {
            helpPtr=helpPtr->next;
        }
    }
    
    if (helpPtr->next!=NULL) {
         return helpPtr;
    }
    else {
        printf("Element nicht gefunden!");
        return NULL;
    }
}
*/
//Sort list


//----------------------------Main----------------------------
int main(int argc, const char * argv[]) {
    printf("Program start\n");
    /*
    //Create new empty list
    HEADER *list1 = createList();
    
    insertElementFront(list1, 1);
    //Elemente an Liste anhängen
   
    
    //Liste ausgeben
    printList(list1);
    */
    return 0;
}
