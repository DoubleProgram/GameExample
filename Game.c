#include "Game.h"

static int WIDTH;
static int HEIGHT;
static Entity player = { GREEN, '@', 0, 0 };
static const Entity coin = { YELLOW, '$', 0, 0 };
static const Entity bomb = { BLUE, 'o', 0, 0 };
//static const POS* bombs;
static const bool gameOver = false;
static int score = 0;
static int amountOfBombs;
//static char** map;
static char* map;

void Setup(int width, int height){
	WIDTH = width;
	HEIGHT = height;
	SetWindowSize(WIDTH, HEIGHT+1); //NOTE: +1 at the height because of the score message
	ShowsCursor(false);
	sColoredPrint(HEIGHT, 0, "Your Score:", WHITE);
	//map = malloc(sizeof(char[HEIGHT][WIDTH])); 
	map = malloc(sizeof(char) * WIDTH * HEIGHT);
	srand(time(NULL));
	amountOfBombs = (HEIGHT * WIDTH) / 10;
	
	//bombs = (POS*) malloc(sizeof(POS) * amountOfBombs);
	
	POS rndp;
	int i;
	for(i = 0; i < amountOfBombs; i++){
		do{
			rndp.x = rand() % HEIGHT;
			rndp.y = rand() % WIDTH;
		}while(map[rndp.x * WIDTH + rndp.y] != NULL);
	
		map[rndp.x * WIDTH + rndp.y] = bomb.c;
		Print(bomb);
	}
}

void Play(){
	do {
		Move();
	} while(!gameOver);
	
	sColoredPrint(0,0,"Game Over!", RED);
}

void Move(){
	switch(getch()){
		case 77: 
			if (CanMove(player.x, player.y + 1)){
				player.y++;
				CheckForCollisions();
		
			}
				
		break; //right
		case 75: break; //left
		case 72: break; //up
		case 80: break; //down
	}
}

bool CanMove(int x, int y){
	return x >= 0 || y >= 0 || x < WIDTH || y < HEIGHT;
}

void CheckForCollisions(){
	if (player.x == coin.x || player.y == coin.y)
		UpdateScore();
}

void SpawnCoin(){

}

void UpdateScore(){
	score++;
	char sscore[20];
	itoa(score, sscore, 10);
	sColoredPrint(HEIGHT, 13, sscore, WHITE);
}
