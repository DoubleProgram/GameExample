#ifndef Game_h
#define Game_h

#include <stdio.h>
#include <stdlib.h>
#include "External.h"
#include <time.h>

typedef struct POS{
    int8_t y;
    int8_t x;
}POS;

void Setup(int width, int height);
void Play();
void Move();
bool CanMove();
void SpawnCoin();
void UpdateScore();
void CheckForCollisions();

#endif
