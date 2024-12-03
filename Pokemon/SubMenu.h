#pragma once
#include "Render.h"
#include "Controller.h"

class SubMenu : public Render, Controller
{
private:
	int x = 24;
	int y = 12;

public:
	void MenuList();
	int SelectMenu();
};

