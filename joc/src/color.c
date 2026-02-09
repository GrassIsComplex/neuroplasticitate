#include <stdlib.h>
#include "raylib.h"
#include "screens.h"

static double gametime = -1.0f;

static bool gameover = 0;

void ColorEnterScreen() {
	gametime = -1.0f;
	gameover = 0;
};

void ColorUpdate(){
	if (IsMouseButtonPressed(0)){
		if (0){
			if (gametime == -1.0f) gametime = 10.0f;
		}
	}
};

void ColorDraw(){
	ClearBackground(WHITE);
	if (!gameover){
		if (gametime == -1.0f){
		}
		else {
			gametime -= GetFrameTime();
			if (gametime <= 0.0f) {gameover = 1; gametime = 0.0f;}
		}
	}else{
	}
};
