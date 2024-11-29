#pragma once
#include "Controller.h"

class MainMenu : public Controller
{
private:
	int x = 24;
	int y = 12;

public:
	void MenuList();
	int SelectMenu();
};