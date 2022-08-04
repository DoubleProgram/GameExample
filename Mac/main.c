#include <stdio.h>
#include <stdlib.h>
#include "External.h"
#include <ncurses.h>
#include "Game.h"

int main(int argc, char *argv[]) {
    initscr();
    curs_set(0);

    if(has_colors() == FALSE){
        endwin();
        printf("Your terminal does not support color\n");
        getch();
        return 0;
    }
   
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
   
    keypad(stdscr,true);
    noecho();
    cbreak();

    refresh();
    
    Setup(60,20);
    Play();
    getch();
    
    endwin();
    return 0;
}
