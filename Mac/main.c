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
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
   
    keypad(stdscr,true);
    noecho();
    cbreak();

    refresh();
    
    Setup(50,20);
    Play();
    getch();
    
    endwin();
    return 0;
}
