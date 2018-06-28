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


//Function prototypes
HEADER* createList(void);
void insertElementFront(HEADER *list, int data);
void insertElementLast (HEADER *list, int data);
void insertElementPosition(HEADER *list, int pos, int data);
void deleteElementFirst(HEADER *list);
void deleteElementLast(HEADER *list);
void deleteAllElements(HEADER *list);
void printList(HEADER *list);
void sortListAsc(HEADER *list);
void sortListDesc(HEADER *list);
int searchElement(HEADER *list, int key);

//----------------------------Functions----------------------------
//Create empty list header
HEADER* createList(){
    
    HEADER *list = malloc(sizeof(HEADER));
    
    list->first=NULL;
    list->last=NULL;
    list->len=0;
    
    return list;
}


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
        ELEM *helpPtr = list->first;
        ELEM *helpPtrPrev = NULL;
        int i;
        
        if(pos<=list->len){
            for(i=1; i<pos; i++){
                helpPtr=helpPtr->next;
            }
            
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

void deleteElementFirst(HEADER *list) {
    if(!list) return;
    
    list->first=list->first->next;
    free(list->first->prev);
    list->first->prev=NULL;
    list->len-=1;
}

void deleteElementLast(HEADER *list) {
    if(!list) return;
    
    list->last=list->last->prev;
    free(list->last->next);
    list->last->next=NULL;
    list->len-=1;
}

void deleteAllElements(HEADER *list){
    if(!list) return;
    
    ELEM *temp = list->first->next;
    
    while(temp->next!=NULL){
        free(temp->prev);
        temp=temp->next;
     }
     free(temp);
     list->first=NULL;
     list->last=NULL;
     list->len=0;
}


//Prints the list from first (left) to last (right)
void printList(HEADER *list){
    
    //Help pointer
    ELEM *helpPtr=list->first;
    int i;
    
    for(i=1; i<=list->len; i++) {
        printf("%d ", helpPtr->data);
        helpPtr=helpPtr->next;
    }
}

void sortListAsc(HEADER *list) {
    if(!list) return;
    if(list->len<2) return;
    
    ELEM *tempElem = list->first;
    int tempZahl;
    
    while (tempElem->next!=NULL) {
        while (tempElem->data>tempElem->next->data){
            //tauschen
            tempZahl=tempElem->data;
            tempElem->data=tempElem->next->data;
            tempElem->next->data=tempZahl;
            //wieder zum Anfang
            tempElem=list->first;
        }
        tempElem=tempElem->next;
    }
}

void sortListDesc(HEADER *list){
    if(!list) return;
    if(list->len<2) return;
    
    ELEM *tempPtr = list->first;
    int tempZahl;
    
    while(tempPtr->next!=NULL){
        while(tempPtr->data<tempPtr->next->data){
            tempZahl=tempPtr->data;
            tempPtr->data=tempPtr->next->data;
            tempPtr->next->data=tempZahl;
            tempPtr=list->first;
        }
        tempPtr=tempPtr->next;
    }
}

int searchElement(HEADER *list, int key){
    if(!list) return 0;
    ELEM *temp = list->first;
    int pos=1;
    
    while(temp != NULL){
        if(temp->data==key){
            return pos;
        }
        temp=temp->next;
        pos+=1;
    }
    return 0;
}




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
    
     //Delete Elements
     //deleteElementFirst(list1);
     //deleteElementLast(list1);
  
    
    //Print list
     printList(list1);
     printf("\n");
    
    //Sort list asc
    sortListAsc(list1);
    printList(list1);
    printf("\n");
    
    //Sort list desc
    sortListDesc(list1);
    printList(list1);
    printf("\n");
    
    //Search element
    printf("Position: %d\n",searchElement(list1, 2));
    
    
    return 0;
}
