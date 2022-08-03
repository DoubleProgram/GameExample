#ifndef EXTERNAL_H_INCLUDED
#define EXTERNAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <stdint.h>

typedef enum Color {
    BLACK = 0,
    DARKBLUE = FOREGROUND_BLUE,
    DARKGREEN = FOREGROUND_GREEN,
    DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
    DARKRED = FOREGROUND_RED,
    DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
    DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
    DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    GRAY = FOREGROUND_INTENSITY,
    BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
    MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,  //TODO: ADD BACKGROUND COLORS AND ALL FORE & BACK -GROUND COLORS COMBINATIONS
}Color;

typedef struct Entity{
    Color color;
    char c;
    int16_t y,x;
}Entity;

void SetWindowSize(int8_t width, int8_t height);
void ShowsCursor(bool visible);
void SetPosition(int16_t X, int16_t Y);
void cPrint(int16_t y, int16_t x, char c);
void sPrint(int16_t y, int16_t x, char* c);
void SetColor(int8_t ForgC);
void cColoredPrint(int16_t y, int16_t x, char c, Color color);
void sColoredPrint(int16_t y, int16_t x, char* s, Color color);
void Print(const Entity entity);

#endif
