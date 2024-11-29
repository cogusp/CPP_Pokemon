#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>

// 키보드 값 정의
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ESC 27

class Controller
{
private:

public:
	Controller();

	void Init();
	void Gotoxy(int x, int y);
	int KeyControl();
};