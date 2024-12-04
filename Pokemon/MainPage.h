#pragma once
#include "Render.h"
#include "Controller.h"
#include "SubMenu.h"

class MainPage : public Controller
{
private:
	Render* mRender;
	SubMenu* mSubMenu;

	int x;
	int y;

public:
	MainPage();
	~MainPage();

	int isPlay = 0;

	int GameLoop();
	void SetMap();
	void SelectSubMenu();
};