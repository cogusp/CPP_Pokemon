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
	char GetIsBuild();									// 다음 위치 맵 반환

	void SetPlayerPos(int x, int y);
	int GetPlayerPosX();							// 현재 플레이어 위치 반환
	int GetPlayerPosY();

	void DrawPlayer();
	void DrawMovePlayer(int x, int y);
	void DrawMap();
	void DrawPokemon();
	void Draw(char ch);
};