#include <stdlib.h>
#include "raylib.h"
#include "screens.h"

#define cnt 2

static Rectangle buttons[cnt*cnt];

static const double maxtime = 20.0f;
static double gametime, changet, flyt;
static bool gamestarted = false, gameover = false;

static int score = 0, bad = -1, good = -1, max_score = 0;

static void SetupRects(void) {
	const int rect_l = 200;
	const int gap = 6;

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
	max_score = 0;
};

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
				flyt = 0.5f;
				good = -1;
				bad = -1;
				if (rand()%2) {good = rand()%(cnt*cnt); max_score++;}
				else bad = rand()%(cnt*cnt);
			}
			if (IsMouseButtonPressed(0)){
				if (good != -1 && CheckCollisionPointRec(GetMousePosition(),buttons[good])){
					flyt = 0.0f;
					score++;
				}
				if (bad != -1 && CheckCollisionPointRec(GetMousePosition(),buttons[bad])){
					flyt = 0.0f;
					score--;
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
			for (int i = 0; i < cnt*cnt; i++){
				DrawRectangleRec(buttons[i], (good == i ? GREEN : ( bad == i ? BLUE : GRAY)));
				DrawRectangleLinesEx(buttons[i], 2, BLACK);
			}
			DrawTextEx(font, TextFormat("Timp ramas: %01.02f", gametime), (Vector2){20, 20}, 40, 2, BLACK);
		}
	} else {
		DrawCenText("Felicitari!", GetScreenHeight()/2-40, 50);
		DrawCenText(TextFormat("Ai obtinut %i/%i puncte", score >= 0 ? score : 0, max_score), GetScreenHeight()/2+12, 50);
	}
};
