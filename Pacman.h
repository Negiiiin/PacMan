#pragma once
#include <windows.h>
#include <conio.h>
#include<stdio.h>
#include<math.h>


void initScreen();
void gotoxy(int x, int y);
void clear_cell(int x, int y);
void clear_cell_Ghost(int x, int y);
void FULL_Circle(int x, int y);
void Draw_Pacman(int x, int y, float mouth_degree, char direction);
void draw_Table();
int waitAndGetDirection(int waitTime, char *direction);
void drawOpeningMouthPacman(int x, int y, char *direction, int p, int q, int u, int z);
int setNextLocation(int *x, int *y, char direction, int a, int b, int p, int q);
void Print_Cookie();
void setNextLocationGhost(int *x, int *y, int* a, int *b);
void Draw_Ghost(int x, int y);

