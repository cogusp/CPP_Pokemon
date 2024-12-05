#pragma once
#include "Render.h"
#include "Controller.h"
#include "SubMenu.h"
#include "Player.h"

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

	int GameLoop(Player* p);
	void SelectSubMenu(Player* p);

	void SetMap();
};