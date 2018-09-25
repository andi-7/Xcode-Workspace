//
//  baum.h
//  Baum
//
//  Created by Andreas Starzer on 20.06.18.
//  Copyright © 2018 Andreas Starzer. All rights reserved.
//

#ifndef baum_h
#define baum_h


typedef struct node {
    struct node *left;
    struct node *right;
    int data;
}NODE;

//Function prototypes
NODE *addNode(NODE *tree, int data);
void preorder(NODE *tree);
void inorder(NODE *tree);
void postorder(NODE *tree);
int NodeCount (NODE *tree);
int TreeSum(NODE *tree);
void searchNode(NODE *tree, int key);

#endif /* baum_h */
