#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Render.h"

// Ű���� �� ����
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ESC 27

class Controller
{
private:
	Render* mRender;

public:
	Controller();
	~Controller();

	int KeyControl();
	void Move();
};