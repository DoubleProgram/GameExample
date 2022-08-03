#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "External.h"
#include <time.h>

typedef struct POS{
	int8_t y;
	int8_t x;
}POS;

void Move();
bool CanMove();
void SpawnCoin();
void UpdateScore();
void CheckForCollisions();

#endif
