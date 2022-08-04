//
//  Game.h
//  Game
//
//  Created by pc on 03.08.22.
//

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

void Setup();
void Play();
void Move();
bool CanMove();
void SpawnCoin();
void UpdateScore();
void CheckForCollisions();

#endif
