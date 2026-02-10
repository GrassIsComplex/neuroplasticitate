#pragma once

enum Screens {
	MAIN,
	AIM,
	COLOR,
	REFLEX
};
void SetScreen(enum Screens);

extern Font font;

void DrawCenText(const char*, int, int);

void MainEnterScreen();
void MainUpdate();
void MainDraw();

void AimEnterScreen();
void AimUpdate();
void AimDraw();

void ColorEnterScreen();
void ColorUpdate();
void ColorDraw();

void ReflexEnterScreen();
void ReflexUpdate();
void ReflexDraw();
