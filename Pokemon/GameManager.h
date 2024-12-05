#pragma once

#include "main.h"
#include "Player.h"
#include "NPC.h"

#include "Shop.h"
#include "MainMenu.h"
#include "TutorialPage.h"
#include "MainPage.h"
#include "LabPage.h"
#include "CenterPage.h"

class GameManager
{
private:
	enum class Pages
	{
		MAIN_MENU = 1,
		TUTORIAL_PAGE,
		MAIN_PAGE,
		INVENTORY,
		SHOP,
		CENTER, 
		LAB,
		SELL_INVENTORY,
		NPC
	};

	Player* mPlayer;
	NPC* mNpc;

	Shop* mShop;
	MainMenu* mMainMenu;
	TutorialPage* mTutorial;
	MainPage* mMain;
	CenterPage* mCenter;
	LabPage* mLab;

	Pages mPage;

public:
	GameManager();
	~GameManager();

	void SetPage(Pages page);
	void StartGame();

	void SetTutorialPage();
	void SetMainPage();
	void SetMainMenu();
	void SetShopPage();
	void SetCenterPage();
	void SetLabPage();
	void SetNpcPage();

	void SetInven();
	void SetSellInven();
};