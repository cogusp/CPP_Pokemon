#pragma once
#include "Render.h"
#include "Controller.h"

class MainMenu : public Render, Controller
{
private:
	int x = 40;
	int y = 12;

public:
	void MenuList();
	int SelectMenu();
};