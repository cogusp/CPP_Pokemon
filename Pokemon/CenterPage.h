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

public:
	CenterPage();
	~CenterPage();

	int isPlay = 0;

	int GameLoop();
	void SetMap();
	void SelectSubMenu();
};

