#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>

#define MAP_WIDTH  55
#define MAP_HEIGHT 20

struct Position
{
	int x = 0;
	int y = 0;
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

	char GetCurrnetMap();				// ���� ��ġ ��
	Position GetPlayerPos();			// ���� �÷��̾� ��ġ

	void DrawPlayer(int x, int y);
	void DrawMap();
	void Draw(char ch);
};