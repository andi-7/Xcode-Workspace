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
    if(list->len==0){ //If list is empty
        list->first=newElement;
        list->last=newElement;
        newElement->next=NULL;
        newElement->prev=NULL;
        newElement->data=data;
        list->len+=1;
   
    } else if(list->len>=1){ //List has elements
        list->first->prev=newElement;
        newElement->next=list->first;
        newElement->prev=NULL;
        list->first=newElement;
        newElement->data=data;
        list->len+=1;
    }
}

void insertElementLast (HEADER *list, int data){
    if(list==NULL) return;
    
    ELEM *newElement = malloc(sizeof(ELEM));
    if(list->len==0){ //If list is empty
        list->first=newElement;
        list->last=newElement;
        newElement->next=NULL;
        newElement->prev=NULL;
        newElement->data=data;
        list->len+=1;

    } else if(list->len>=1){ //List has elements
        list->last->next=newElement;
        newElement->prev=list->last;
        newElement->next=NULL;
        list->last=newElement;
        newElement->data=data;
        list->len+=1;
    }
}

void insertElementPosition(HEADER *list, int pos, int data) {
    if(!list) return;
    
    ELEM *newElement = malloc(sizeof(ELEM));
    
    if(list->len==0){ //If list is empty
        list->first=newElement;
        list->last=newElement;
        newElement->next=NULL;
        newElement->prev=NULL;
        newElement->data=data;
        list->len+=1;
        
    } else if(list->len>=1){ //List has elements
        ELEM *helpPtr = malloc(sizeof(ELEM));
        ELEM *helpPtrPrev = malloc(sizeof(ELEM));
        int i;
        
        helpPtr=list->first;
        
        if(pos<=list->len){
            for(i=1; i<pos; i++){
                helpPtr=helpPtr->next;
            }
            printf("%d\n",helpPtr->data);
            
            helpPtrPrev=helpPtr->prev;
            
            newElement->next=helpPtr;
            newElement->prev=helpPtrPrev;
            helpPtr->prev=newElement;
            helpPtrPrev->next=newElement;
            newElement->data=data;
            
            
            list->len+=1;
            
            } else if (pos>list->len) { //If position is more than the list's length
                insertElementLast(list, data);
        }
    }
}



//Prints the list from first (left) to last (right)
void printList(HEADER *list){
    
    //Help pointer
    ELEM *helpPtr=malloc(sizeof(ELEM));
    int i;
    
    helpPtr=list->first;
    
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
    
     //Create new empty list
     HEADER *list1 = createList();
    
     //Append elements
     insertElementFront(list1, 1);
     insertElementFront(list1, 2);
     insertElementFront(list1, 3);
     insertElementLast(list1, 1);
     insertElementLast(list1, 2);
     insertElementLast(list1, 3);
     insertElementPosition(list1, 4, 7);
    
     //Liste ausgeben
     printList(list1);
     printf("\n");
    
    return 0;
}
