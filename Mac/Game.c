//
//  Game.c
//  Game
//
//  Created by pc on 03.08.22.
//

#include "Game.h"
#include <time.h>

static int WIDTH;
static int HEIGHT;
static Entity player = { 1, '@', 0, 0 };
static const Entity coin = { 2, '$', 0, 0 };
static const Entity bomb = { 3, 'o', 0, 0 };
static bool gameOver = false;
static int score = 0;
static char* map;

void Setup(int width, int height){
    WIDTH = width;
    HEIGHT = height;
    map = (char*)calloc(WIDTH * HEIGHT,sizeof(char));
    srand((unsigned)time(NULL));
    int amountOfBombs = (HEIGHT * WIDTH) / 10;
    int amountOfCoins = amountOfBombs / 5;
    mvaddstr(HEIGHT,0,"Your Score: 0");
    
    POS rndp;
    int i;
    for(i = 0; i < amountOfBombs; i++){
        do{
            rndp.x = rand() % HEIGHT;
            rndp.y = rand() % WIDTH;
        }while(map[rndp.x * WIDTH + rndp.y] != 0);
    
        map[rndp.x * WIDTH + rndp.y] = bomb.c;
        ccPrint(bomb.c, rndp.x, rndp.y, bomb.color);
    }
    
    for(i = 0; i < amountOfCoins; i++){
        do{
            rndp.x = rand() % HEIGHT;
            rndp.y = rand() % WIDTH;
        }while(map[rndp.x * WIDTH + rndp.y] != 0);
    
        map[rndp.x * WIDTH + rndp.y] = coin.c;
        ccPrint(coin.c, rndp.x, rndp.y, coin.color);
    }
    
    do{
        rndp.x = rand() % HEIGHT;
        rndp.y = rand() % WIDTH;
    }while(map[rndp.x * WIDTH + rndp.y] != 0);
    
    player.x = rndp.x;
    player.y = rndp.y;
    Print(player);
    refresh();
}

void Play(){
    do {
        Move();
        refresh();
    } while(!gameOver);
    
    mvaddstr(HEIGHT/2, WIDTH/2-6, "You've lost!");
}

void Move(){
    switch(getch()){
        case KEY_RIGHT:
            if (CanMove(player.x, player.y + 1)){
                mvaddch(player.x, player.y, ' ');
                player.y++;
                Print(player);
                CheckForCollisions();
            }
        break;
        case KEY_LEFT:
            if (CanMove(player.x, player.y - 1)){
                mvaddch(player.x, player.y, ' ');
                player.y--;
                Print(player);
                CheckForCollisions();
            }
            break;
        case KEY_UP:
            if (CanMove(player.x - 1, player.y)){
                mvaddch(player.x, player.y, ' ');
                player.x--;
                Print(player);
                CheckForCollisions();
            }
            break;
        case KEY_DOWN:
            if (CanMove(player.x + 1, player.y)){
                mvaddch(player.x, player.y, ' ');
                player.x++;
                Print(player);
                CheckForCollisions();
            }
            break;
    }
}

bool CanMove(int x, int y){
    return x >= 0 && y >= 0 && x < HEIGHT && y < WIDTH;
}

void CheckForCollisions(){
    if (map[player.x * WIDTH + player.y] == coin.c){
        map[player.x * WIDTH + player.y] = ' ';
        UpdateScore();
    }
        
    else if(map[player.x * WIDTH + player.y] == bomb.c){
        gameOver = true;
    }
}

void UpdateScore(){
    score++;
    char* sscore;
    sscore = itoa(score, 10);
    mvaddstr(HEIGHT, 12, sscore);
}
