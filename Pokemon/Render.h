#pragma once
#include <Windows.h>
#include <iostream>
//#include <conio.h>

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
	char map[MAP_HEIGHT][MAP_WIDTH + 1];
	char isBuild;
	char temp;

public:
	Render();
	~Render();

	void Init();
	void Gotoxy(int x, int y);

	void SetMap(char arr[][MAP_WIDTH + 1]);
	
	void SetIsBuildZero();
	char GetIsBuild();									// ���� ��ġ �� ��ȯ

	void SetPlayerPos(int x, int y);
	int GetPlayerPosX();							// ���� �÷��̾� ��ġ ��ȯ
	int GetPlayerPosY();

	void DrawPlayer();
	void DrawMovePlayer(int x, int y);
	void DrawMap();
	void DrawPokemon();
	void Draw(char ch);
};