#pragma once

enum Screens {
	MAIN,
	AIM,
	COLOR,
	REFLEX
};

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
