#include <stdlib.h>
#include "raylib.h"
#include "screens.h"

static const int target_size = 50;

static int score = 0;

static double gametime = -1.0f;

static bool gameover = 0;

static Vector2 target_pos;

static void DrawTarget(){
	DrawCircle(target_pos.x, target_pos.y, target_size, RED);
};

void AimEnterScreen() {
	target_pos.x = GetScreenWidth()/2;
	target_pos.y = GetScreenHeight()/2;
	gametime = -1.0f;
	gameover = 0;
	score = 0;
};

void AimUpdate(){
	if (IsMouseButtonPressed(0)){
		if (CheckCollisionPointCircle(GetMousePosition(),target_pos,target_size)){
			if (gametime == -1.0f) gametime = 10.0f;
			target_pos.x = rand() % (GetScreenWidth()  - 2 * target_size) + target_size;
			target_pos.y = rand() % (GetScreenHeight() - 2 * target_size) + target_size;
			++score;
		}
	}
};

void AimDraw(){
	ClearBackground(RAYWHITE);
	if (!gameover){
		DrawTarget();
		if (gametime == -1.0f){
			DrawCenText("Apasa pe tinte in cel mai scult timp", 400, 50);
			DrawTextEx(font, "Timp ramas: 0.00", (Vector2){20, 20}, 40, 2, BLACK);
		}
		else {
			DrawTextEx(font, TextFormat("Timp ramas: %02.02f",gametime), (Vector2){20, 20}, 40, 2, BLACK);
			gametime -= GetFrameTime();
			if (gametime <= 0.0f) {gameover = 1; gametime = 0.0f;}
		}
	}else{
		DrawCenText("Felicitari!", GetScreenHeight()/2-40, 50);
		DrawCenText(TextFormat("Ai obtinut %i puncte", score), GetScreenHeight()/2+12, 50);
	}
};
