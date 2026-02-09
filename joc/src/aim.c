#include <stdlib.h>
#include "raylib.h"
#include "screens.h"

static const int target_size = 25;

static int score = 0;

static double gametime = -1.0f;

static bool gameover = 0;

static Vector2 target_pos;

static void DrawTarget(){
	DrawCircle(target_pos.x, target_pos.y, 25, RED);
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
	ClearBackground(WHITE);
	if (!gameover){
		DrawTarget();
		if (gametime == -1.0f){
			DrawCenText("Apasa pe tinte in cel mai scult timp", 400, 20);
			DrawText(TextFormat("Timp ramas: 0.00"), 20, 20, 20, BLACK);
		}
		else {
			DrawText(TextFormat("Timp ramas: %02.02f",gametime), 20, 20, 20, BLACK);
			gametime -= GetFrameTime();
			if (gametime <= 0.0f) {gameover = 1; gametime = 0.0f;}
		}
	}else{
		DrawCenText("Felicitari!", GetScreenHeight()/2-20, 30);
		DrawCenText(TextFormat("Ai obtinut %i puncte", score), GetScreenHeight()/2+12, 20);
	}
};
