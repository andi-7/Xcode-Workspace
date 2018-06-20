//
//  liste.h
//  MiniProjekt1
//
//  Created by Andreas Starzer on 25.05.18.
//  Copyright © 2018 Andreas Starzer. All rights reserved.
//

#ifndef project1_h
#define project1_h

//----------Structs----------

typedef struct header{
    struct elem *first;
    struct elem *last;
    int len;
}HEADER;

typedef struct elem{
    struct elem *next;
    struct elem *prev;
    int data;
}ELEM;


//----------Funktionen----------

/*
 * Listen-Funktionen
 * File lesen
 *     -Existenzprüfung
 *     -Download
 *    -Time-Stamp-Vergleich
 *    -neues File speichern
 *
 */

#endif /* project1_h */
