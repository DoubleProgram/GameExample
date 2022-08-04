//
//  External.h
//  Game
//
//  Created by pc on 03.08.22.
//

#ifndef External_h
#define External_h
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>

typedef struct Entity{
    int color;
    char c;
    int16_t y,x;
}Entity;

void Print(const Entity entity);

//colored char Print
void ccPrint(char, int, int, int);

//colored string Print
void csPrint(char*, int, int, int);

char* itoa(int val, int base);

#endif /* External_h */
