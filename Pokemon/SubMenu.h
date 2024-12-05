#pragma once
#include "Render.h"
#include "Controller.h"
#include "Player.h"
#include <Windows.h>

class SubMenu : public Render, Controller
{
private:
	int x = MAP_WIDTH / 2;
	int y = MAP_HEIGHT / 3;

public:
	void MenuList();
	int SelectMenu();
	void Menu(Player* p);
};