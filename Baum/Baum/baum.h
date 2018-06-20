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

#endif /* baum_h */
