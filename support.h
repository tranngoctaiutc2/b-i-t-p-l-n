#ifndef support
#define support
#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
void setFullScreen();
void exitFullScreen();
void textcolor(WORD color); 
void SetBGColor(WORD color);
void setColor( int maunen , int mauchu);
void textcolor(WORD color) 
{ 
    HANDLE hConsoleOutput; 
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info; 
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info); 

    WORD wAttributes = screen_buffer_info.wAttributes; 
    color &= 0x000f; 
    wAttributes &= 0xfff0; 
    wAttributes |= color; 

    SetConsoleTextAttribute(hConsoleOutput, wAttributes); 
}


void SetBGColor(WORD color) 
{ 
    HANDLE hConsoleOutput; 
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info; 
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info); 

    WORD wAttributes = screen_buffer_info.wAttributes; 
    color &= 0x000f; 
    color <<= 4; 
    wAttributes &= 0xff0f; 
    wAttributes |= color; 

    SetConsoleTextAttribute(hConsoleOutput, wAttributes); 
}

void setColor(int maunen, int mauchu)
{
	SetBGColor(maunen);
	textcolor(mauchu);
}
void gotoxy(short int x,short int y) 
{ 
    HANDLE hConsoleOutput; 
    COORD Cursor_an_Pos = { x,y}; 
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos); 
}
void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}
#endif
