#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>

#define MAP_WIDTH  55
#define MAP_HEIGHT 20

struct Position
{
	int x = 25;
	int y = 10;
};

class Render
{
private:
	Position* sPosition;
	bool isFirst;
	char temp;

public:
	Render();
	~Render();

	void Init();
	void Gotoxy(int x, int y);

	char GetCurrnetMap();						// ���� ��ġ ��

	Position GetPlayerPos();					// ���� �÷��̾� ��ġ ��ȯ

	void DrawPlayer(int x, int y);
	void DrawMap();
	void Draw(char ch);
};