#include "Game.h"
#include <time.h>

static int WIDTH;
static int HEIGHT;
static Entity player = { WHITE, '@', 0, 0 };
static const Entity coin = { YELLOW, '$', 0, 0 };
static const Entity bomb = { DARKRED, 'o', 0, 0 };
static bool gameOver = false;
static int score = 0;
static char* map;

void Setup(int width, int height){
    WIDTH = width;
    HEIGHT = height;
    SetWindowSize(width,height+1);
    ShowsCursor(false);
    SetConsoleTitle("Demo");

    map = (char*)calloc(WIDTH * HEIGHT,sizeof(char));
    srand((unsigned)time(NULL));
    int amountOfBombs = (HEIGHT * WIDTH) / 10;
    int amountOfCoins = amountOfBombs / 5;
    sPrint("Your Score: 0", HEIGHT, 0);
    POS rndp;
    int i;
    
    for(i = 0; i < amountOfBombs; i++){
        do{
            rndp.x = rand() % HEIGHT;
            rndp.y = rand() % WIDTH;
        }while(map[rndp.x * WIDTH + rndp.y] != 0);
    
        map[rndp.x * WIDTH + rndp.y] = bomb.c;
        cColoredPrint(bomb.c, rndp.x, rndp.y, bomb.color);
    }
    
    for(i = 0; i < amountOfCoins; i++){
        do{
            rndp.x = rand() % HEIGHT;
            rndp.y = rand() % WIDTH;
        }while(map[rndp.x * WIDTH + rndp.y] != 0);
    
        map[rndp.x * WIDTH + rndp.y] = coin.c;
        cColoredPrint(coin.c, rndp.x, rndp.y, coin.color);
    }
    
    do{
        rndp.x = rand() % HEIGHT;
        rndp.y = rand() % WIDTH;
    }while(map[rndp.x * WIDTH + rndp.y] != 0);
    
    player.x = rndp.x;
    player.y = rndp.y;
    Print(player);
}

void Play(){
    do {
        Move();
    } while(!gameOver);
    
    free(map);
    sPrint("You've lost!", HEIGHT/2, WIDTH/2-6);
}

void Move(){
    switch(getch()){
        case 77: //right key
            if (CanMove(player.x, player.y + 1)){
                cPrint(' ', player.x, player.y);
                player.y++;
                Print(player);
                CheckForCollisions();
            }
        break;
        case 75: //left key
            if (CanMove(player.x, player.y - 1)){
                cPrint(' ', player.x,player.y);
                player.y--;
                Print(player);
                CheckForCollisions();
            }
            break;
        case 72: //up key
            if (CanMove(player.x - 1, player.y)){
                cPrint(' ', player.x,player.y);
                player.x--;
                Print(player);
                CheckForCollisions();
            }
            break;
        case 80: //down key
            if (CanMove(player.x + 1, player.y)){
                cPrint(' ', player.x,player.y);
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
    char sscore[20];
    itoa(score,sscore, 10);
    sPrint(sscore, HEIGHT, 12);
}
