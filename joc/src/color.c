#include <stdlib.h>
#include "raylib.h"
#include "screens.h"

static const int ncolor = 5;
static const Color colors[ncolor] = {RED, YELLOW, GREEN, BLUE, PURPLE}; //{RED, YELLOW, GREEN, PURPLE, MAROON, BLUE, PINK, SKYBLUE, GOLD};
static int col[9];
static struct {
	int col;
	Rectangle rect;
} buttons[9];

static const double maxtime = 20.0f;
static const double prevtime = 2.0f;
static double previewtime, solvetime;
static bool gamestarted = false, previewing = false, gameover = false;

static int finalscore = 0;

static void SetupRects(void) {
	const int rect_l = 70;
	const int gap = 8;

	const int grid_w = 3 * rect_l + 2 * gap;
	const int grid_h = 3 * rect_l + 2 * gap;

	int x = GetScreenWidth() / 2 - grid_w / 2;
	int y = GetScreenHeight() / 2 - grid_h / 2;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			buttons[i * 3 + j].rect = (Rectangle){ x + j * (rect_l + gap), y + i * (rect_l + gap), rect_l, rect_l };
		}
	}
}

static void RandomizeArray() {
	for (int i=0; i < 9; i++){
		col[i] = rand()%ncolor;
	}
};

static int GetCorrect() {
	int c = 0;
	for (int i = 0; i < 9; i++){
		if (col[i] == buttons[i].col) c++;
	}
	return c;
}

void ColorEnterScreen() {
	previewing = false;
	gamestarted = false;
	gameover = false;
	previewtime = 0.0f;
	solvetime = 0.0f;
	SetupRects();
	RandomizeArray();
};

#include <stdio.h>

void ColorUpdate(){
	if (previewing){
		previewtime -= GetFrameTime();
		if (previewtime <= 0) {
			previewtime = 0.0f;
			previewing = false;
			gamestarted = true;
			solvetime = maxtime;
		}
	}
	if (gamestarted){
		solvetime -= GetFrameTime();
		if (solvetime <= 0) {
			gamestarted = false;
			gameover = true;
			finalscore = GetCorrect();
		}
	}
	if (IsMouseButtonPressed(0)){
		if (!previewing && !gamestarted && !gameover){
			previewing = true;
			previewtime = prevtime;
		}
		for (int i = 0; i < 9; i++){
			if (CheckCollisionPointRec(GetMousePosition(),buttons[i].rect)){
				if (!previewing) {
					buttons[i].col = (buttons[i].col+1)%ncolor;
					if (GetCorrect() == 9){
						gamestarted = false;
						gameover = true;
						finalscore = 9;
					}
				}
			}
		}
	}
};

void ColorDraw(){
	ClearBackground(RAYWHITE);
	if (!previewing && !gamestarted && !gameover) 
	{
		DrawCenText(TextFormat("Fa clic pentru a incepe",prevtime),GetScreenHeight()/2 - 20, 50);
		DrawCenText(TextFormat("Vei avea%2.0f secunde sa memorezi modelul",prevtime),GetScreenHeight()/2 + 25, 50);
	}
	else
		if (!gameover){
			for (int i = 0; i < 9; i++){
				DrawRectangleRec(buttons[i].rect, previewing ? colors[col[i]] : colors[buttons[i].col]);
				DrawRectangleLinesEx(buttons[i].rect, 2, BLACK);
			}
			if (previewing) DrawTextEx(font, TextFormat("Timp ramas: %01.02f",previewtime), (Vector2){20, 20}, 40, 2, BLACK);
			if (gamestarted) DrawTextEx(font, TextFormat("Timp ramas: %01.02f",solvetime), (Vector2){20, 20}, 40, 2, BLACK);
		}else{
			DrawCenText(TextFormat("Scor: %d/9 in %2.02f secunde",finalscore, maxtime - solvetime),GetScreenHeight()/2 - 15, 30);
		}
};
