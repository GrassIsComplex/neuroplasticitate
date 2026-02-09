#include <stdlib.h>
#include <time.h>
#include "raylib.h"
#include "screens.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

const int screenWidth = 800;
const int screenHeight = 450;

enum Screens current_screen;

void UpdateDrawFrame(void);
void SetScreen(enum Screens);

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Neuroplasticitate");

	srand(time(NULL));

	SetScreen(MAIN);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);
    while (!WindowShouldClose())
        UpdateDrawFrame();
#endif
    CloseWindow();

    return 0;
}

void DrawCenText(const char *t, int y, int s){
	DrawText(t, GetScreenWidth()/2 - MeasureText(t, s)/2, y, s, BLACK);
};

void SetScreen(enum Screens new_screen){
	switch (new_screen) {
		case MAIN:
			MainEnterScreen();
		case COLOR:
			ColorEnterScreen();
		case AIM:
			AimEnterScreen();
	};
	current_screen = new_screen;
}

void UpdateDrawFrame(void)
{
	switch (current_screen){
		case MAIN:{
			MainUpdate();
			BeginDrawing();
			MainDraw();
			EndDrawing();
			break;
		}
		case AIM:{
			AimUpdate();
			BeginDrawing();
			AimDraw();
			EndDrawing();
			break;
		}
		case COLOR:{
			ColorUpdate();
			BeginDrawing();
			ColorDraw();
			EndDrawing();
			break;
		}
		default:
			break;
	}
}
