//
//  main.c
//  Baum
//
//  Created by Andreas Starzer on 20.06.18.
//  Copyright © 2018 Andreas Starzer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "baum.h"


//--------------------Functions--------------------

NODE *addNode(NODE *tree, int data){
    if(tree == NULL) {
        tree = malloc(sizeof(NODE));
        tree->left=NULL;
        tree->right=NULL;
        tree->data=data;
    } else if(tree->data>=data) {
        tree->left=addNode(tree->left, data);
    } else {
        tree->right=addNode(tree->right, data);
    }
    return tree;
}

void preorder(NODE *tree) {
    if(!tree) return;
    
    printf("%d ",tree->data);
    preorder(tree->left);
    preorder(tree->right);
}

void inorder(NODE *tree) {
    if(!tree) return;
    
    preorder(tree->left);
    printf("%d ",tree->data);
    preorder(tree->right);
}

void postorder(NODE *tree) {
    if(!tree) return;
    
    preorder(tree->left);
    preorder(tree->right);
    printf("%d ",tree->data);
}

int NodeCount (NODE *tree) {
    if(!tree) return 0;;
    
    static int count=0;
    count+=1;
    NodeCount(tree->left);
    NodeCount(tree->right);
    
    return count;
}

int TreeSum(NODE *tree){
    if(!tree) return 0;
    
    static int sum=0;
    sum+=tree->data;
    TreeSum(tree->left);
    TreeSum(tree->right);
  
    return sum;
}

void searchNode(NODE *tree, int key){
    if(tree==NULL) return;
    
    if(tree->data==key) {
        printf("Knoten gefunden!\n");
    } else {
        searchNode(tree->left, key);
        searchNode(tree->right, key);
    }
   
}



//--------------------Main--------------------
int main(int argc, const char * argv[]) {
   
    NODE *tree1=NULL;
    
    //Add nodes
    tree1=addNode(tree1, 4);
    tree1=addNode(tree1, 1);
    tree1=addNode(tree1, 9);
    tree1=addNode(tree1, 4);
    tree1=addNode(tree1, 7);
    tree1=addNode(tree1, 6);
    tree1=addNode(tree1, 8);

    //Print tree
    preorder(tree1);
    printf("\n");
    inorder(tree1);
    printf("\n");
    postorder(tree1);
    printf("\n");
    
    printf("Anzahl der Knoten: %d\n", NodeCount(tree1));
    printf("Summe: %d\n",TreeSum(tree1));
   
    searchNode(tree1, 4);
    
    return 0;
}
