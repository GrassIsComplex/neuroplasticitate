#include <stdlib.h>
#include "raylib.h"
#include "screens.h"

static double gametime = -1.0f;

static bool gameover = false;

static const Color colors[9] = {RED, YELLOW, GREEN, PURPLE, MAROON, BLUE, PINK, SKYBLUE, MAGENTA};

static int col[9];

static Rectangle buttons[9] = {};

void SetupRects() {
	const int rect_l = 25;
	int cx = GetScreenWidth()/2;
	int cy = GetScreenHeight()/2;
	for (int i = -1; i < 2; i++)
	for (int j = -1; j < 2; j++)
	{
		Rectangle new_rect = {cx + rect_l*i, cy + rect_l*j, rect_l, rect_l};
		buttons[(1+i)*3+(1+j)] = new_rect;
	}
}

void RandomizeArray() {
	for (int i=0; i < 9; i++){
		col[i] = rand()%9;
	}
};

void ColorEnterScreen() {
	gametime = -1.0f;
	gameover = false;
	SetupRects();
	RandomizeArray();
};

void ColorUpdate(){
	if (IsMouseButtonPressed(0)){
	}
};

void ColorDraw(){
	ClearBackground(GREEN);
	for (int i = 0; i < 9; i++){
		DrawRectangleRec(buttons[i], BLACK);
	}
	if (!gameover){
	}else{
	}
};
