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

        const int btnW = 220;
        const int btnH = 60;
        const int spacing = 20;

        int cx = GetScreenWidth()/2 - btnW/2;
        int baseY = GetScreenHeight()/2 - 30;

        Rectangle btnAim = { cx, baseY, btnW, btnH };
        Rectangle btnColor = { cx, baseY + btnH + spacing, btnW, btnH };
        Rectangle btnPlaceholder = { cx, baseY + 2*(btnH + spacing), btnW, btnH };

        if (CheckCollisionPointRec(mouse, btnAim))
            SetScreen(AIM);

        if (CheckCollisionPointRec(mouse, btnColor))
            SetScreen(COLOR);

        if (CheckCollisionPointRec(mouse, btnPlaceholder))
            SetScreen(REFLEX);
    }
}

void MainDraw()
{
	ClearBackground(RAYWHITE);

    DrawCenText("Neuroplasticitate", 120, 46);

    Vector2 mouse = GetMousePosition();

    const int btnW = 220;
    const int btnH = 60;
    const int spacing = 20;

    int cx = GetScreenWidth()/2 - btnW/2;

    int baseY = GetScreenHeight()/2 - 30;

	const int textoff = 10;

    Rectangle btnAim = { cx, baseY, btnW, btnH };
    Rectangle btnColor = { cx, baseY + btnH + spacing, btnW, btnH };
    Rectangle btnPlaceholder = { cx, baseY + 2*(btnH + spacing), btnW, btnH };

    DrawRectangleRec(btnAim, CheckCollisionPointRec(mouse, btnAim) ? GRAY : LIGHTGRAY);
    DrawRectangleLinesEx(btnAim, 2, BLACK);
    DrawCenText("Tinte", btnAim.y + textoff, 40);

    DrawRectangleRec(btnColor, CheckCollisionPointRec(mouse, btnColor) ? GRAY : LIGHTGRAY);
    DrawRectangleLinesEx(btnColor, 2, BLACK);
    DrawCenText("Culori", btnColor.y + textoff, 40);

    DrawRectangleRec(btnPlaceholder, CheckCollisionPointRec(mouse, btnPlaceholder) ? GRAY : LIGHTGRAY);
    DrawRectangleLinesEx(btnPlaceholder, 2, BLACK);
    DrawCenText("Reflex", btnPlaceholder.y + textoff, 40);
}


