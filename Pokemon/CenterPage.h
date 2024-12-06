#pragma once
#include "Pokemon.h"
#include "Render.h"
#include "Controller.h"
#include "SubMenu.h"
#include <iostream>

class CenterPage : public Controller
{
private:
	Render* mRender;
	SubMenu* mSubMenu;

	int x;
	int y;

public:
	CenterPage();
	~CenterPage();

	int isPlay = 0;

	int GameLoop(Player* p);
	void SetMap();
	void SelectSubMenu();
	void Heal(Player* p);
};

