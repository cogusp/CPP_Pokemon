#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Player.h"
//#include <vector>

class Render
{
private:
	//std::vector<char[20][29]> mapList;
	//char map[20][29];
	bool isFirst = true;
	Player::Position* sPosition;

public:

	void Init();
	void Gotoxy(int x, int y);

	void DrawPlayer(int, int);
	void DrawMap();
	void Draw(char ch)
};

