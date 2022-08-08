#include "External.h"

void SetWindowSize(int8_t width, int8_t height){
	COORD      coord = { width, height };
    SMALL_RECT rmin  = { 0, 0, 1, 1 };
    SMALL_RECT rect  = { 0, 0, width-1, height-1 };

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(Handle, TRUE, &rmin);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &rect);
}

void ShowsCursor(bool visible){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = visible;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void SetPosition(int16_t X, int16_t Y){
    HANDLE Screen;
    Screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position = { Y, X };
    SetConsoleCursorPosition(Screen, Position);
}

void cPrint(char c, int16_t x, int16_t y){
    SetPosition(x,y);
    printf("%c",c);
}

void sPrint(char* s, int16_t x, int16_t y){
    SetPosition(x,y);
    printf("%s",s);
}

void SetColor(int8_t ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void cColoredPrint(char c, int16_t x, int16_t y, Color color){
    SetColor(color);
    SetPosition(x,y);
    printf("%c",c);
    SetColor(WHITE);
}

void sColoredPrint(char* s, int16_t x, int16_t y, Color color){
    SetColor(color);
    SetPosition(x,y);
    printf("%s",s);
    SetColor(WHITE);
}

void Print(const Entity entity){
    cPrint(entity.c,entity.x,entity.y);
}
