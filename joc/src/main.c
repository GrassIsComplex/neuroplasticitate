#include <stdlib.h>
#include <time.h>
#include "raylib.h"
#include "screens.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

const int screenWidth = 1200;
const int screenHeight = 650;

Font font;

enum Screens current_screen;

void UpdateDrawFrame(void);
void SetScreen(enum Screens);

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Neuroplasticitate");

	srand(time(NULL));

	font = LoadFontEx("resources/Roboto-Regular.ttf", 120, NULL, 0);

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
	DrawTextEx(font, t, (Vector2){GetScreenWidth()/2 - MeasureTextEx(font, t, s, 2).x/2, y}, s, 2, BLACK);
};

void SetScreen(enum Screens new_screen){
	switch (new_screen) {
		case MAIN:
			MainEnterScreen();
		case COLOR:
			ColorEnterScreen();
		case AIM:
			AimEnterScreen();
		case REFLEX:
			ReflexEnterScreen();
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
		case REFLEX:{
			ReflexUpdate();
			BeginDrawing();
			ReflexDraw();
			EndDrawing();
		}
		default:
			break;
	}
}
