#include <stdlib.h>
#include "raylib.h"
#include "screens.h"

static Rectangle buttons[25];

static const double maxtime = 20.0f;
static double gametime, changet, flyt;
static bool gamestarted = false, gameover = false;

static int score = 0, bad = -1, good = -1;

static void SetupRects(void) {
	const int cnt = 5; // 4x4 grid

	const int rect_l = 70;
	const int gap = 8;

	const int grid_w = cnt * rect_l + (cnt-1) * gap;
	const int grid_h = cnt * rect_l + (cnt-1) * gap;

	int x = GetScreenWidth() / 2 - grid_w / 2;
	int y = GetScreenHeight() / 2 - grid_h / 2;

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			buttons[i * cnt + j] = (Rectangle){ x + j * (rect_l + gap), y + i * (rect_l + gap), rect_l, rect_l };
		}
	}
}

void ReflexEnterScreen() {
	gamestarted = false;
	gameover = false;
	gametime = 0.0f;
	changet = 0.0f;
	flyt = 0.0f;
	SetupRects();
	good = -1;
	bad = -1;
};

#include <stdio.h>

void ReflexUpdate(){
	if (!gameover) {
		if (!gamestarted) {
			if (IsMouseButtonPressed(0)){
				gamestarted = true;
				gametime = maxtime;
			}
		} else {
			gametime -= GetFrameTime();
			changet -= GetFrameTime();
			flyt -= GetFrameTime();
			if (gametime <= 0.0f) {
				gametime = 0.0f;
				gameover = true;
			}
			if (flyt <= 0.0f) good = bad = -1;
			if (changet <= 0.0f) {
				changet = 1.2f + rand()%50/100.0;
				flyt = 1.0f;
				good = -1;
				bad = -1;
				if (rand()%2) good = rand()%25;
				else bad = rand()%25;
				puts(TextFormat("%.2f",changet));
			}
			if (IsMouseButtonPressed(0)){
				if (good != -1 && CheckCollisionPointRec(GetMousePosition(),buttons[good])){
					flyt = 0.0f;
				}
				if (bad != -1 && CheckCollisionPointRec(GetMousePosition(),buttons[bad])){
					flyt = 0.0f;
				}
			}
		}
	} else {

	}
};

void ReflexDraw(){
	ClearBackground(RAYWHITE);

	if (!gameover) {
		if (!gamestarted) {
			DrawCenText("Fa clic pentru a incepe",GetScreenHeight()/2 - 20, 50);
			DrawCenText("Apasa pe patratele verzi, dar nu pe cele albastre",GetScreenHeight()/2 + 25, 50);
		} else {
			for (int i = 0; i < 25; i++){
				DrawRectangleRec(buttons[i], (good == i ? GREEN : ( bad == i ? BLUE : GRAY)));
				DrawRectangleLinesEx(buttons[i], 2, BLACK);
			}
		}
	} else {
		
	}
};
