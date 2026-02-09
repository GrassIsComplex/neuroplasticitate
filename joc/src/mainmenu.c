#include "raylib.h"
#include "screens.h"

void SetScreen(enum Screens new_screen);

void MainEnterScreen()
{

}

void MainUpdate()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse = GetMousePosition();

        int cx = GetScreenWidth()/2 - 100;

        Rectangle btnAim = { cx, 180, 200, 40 };
        Rectangle btnColor = { cx, 240, 200, 40 };
        Rectangle btnPlaceholder = { cx, 300, 200, 40 };

        if (CheckCollisionPointRec(mouse, btnAim))
            SetScreen(AIM);

        if (CheckCollisionPointRec(mouse, btnColor))
            SetScreen(COLOR);

        if (CheckCollisionPointRec(mouse, btnPlaceholder))
        {

        }
    }
}

void MainDraw()
{
    ClearBackground(WHITE);

	DrawCenText("Neuroplasticitate", 80, 30);

    int cx = GetScreenWidth()/2 - 100;

	Vector2 mouse = GetMousePosition();

    Rectangle btnAim = { cx, 180, 200, 40 };
    Rectangle btnColor = { cx, 240, 200, 40 };
    Rectangle btnPlaceholder = { cx, 300, 200, 40 };

    DrawRectangleRec(btnAim, CheckCollisionPointRec(mouse, btnAim) ? GRAY : LIGHTGRAY);
    DrawRectangleLinesEx(btnAim, 2, BLACK);
    DrawCenText("Tinte", 190, 20);

    DrawRectangleRec(btnColor, CheckCollisionPointRec(mouse, btnColor) ? GRAY : LIGHTGRAY);
    DrawRectangleLinesEx(btnColor, 2, BLACK);
    DrawCenText("Culori", 250, 20);

    DrawRectangleRec(btnPlaceholder, CheckCollisionPointRec(mouse, btnPlaceholder) ? GRAY : LIGHTGRAY);
    DrawRectangleLinesEx(btnPlaceholder, 2, BLACK);
    DrawCenText("Placeholder", 310, 20);
}

