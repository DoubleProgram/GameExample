//
//  External.c
//  Game
//
//  Created by pc on 03.08.22.
//

#include <stdio.h>
#include "External.h"

void Print(const Entity entity){
    attron(COLOR_PAIR(entity.color));
    mvaddch(entity.x,entity.y, entity.c);
    attroff(COLOR_PAIR(entity.color));
}

void csPrint(char* s, int x, int y, int color){
    attron(COLOR_PAIR(color));
    mvaddstr(x, y, s);
    attroff(COLOR_PAIR(color));
}

void ccPrint(char c, int x, int y, int color){
    attron(COLOR_PAIR(color));
    mvaddch(x, y, c);
    attroff(COLOR_PAIR(color));
}

char* itoa(int val, int base){
    static char buf[32] = {0};
    int i = 30;
    
    for(; val && i ; --i, val /= base)
        buf[i] = "0123456789abcdef"[val % base];
    
    return &buf[i+1];
}
