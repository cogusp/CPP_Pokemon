#pragma once

#include "main.h"
#include "Player.h"
#include "Shop.h"
#include "MainMenu.h"
#include "TutorialPage.h"
#include "MainPage.h"

class GameManager
{
private:
	enum class Pages
	{
		MAIN_MENU = 1,
		TUTORIAL_PAGE,
		MAIN_PAGE,
		SUB_MENU,
		INVENTORY,
		SHOP,
		SELL_INVENTORY,
	};

	//Player* mPlayer;
	Shop* mShop;
	MainMenu* mMainMenu;
	TutorialPage* mTutorial;
	MainPage* mMain;

	Pages mPage;
	//int mCoin;

public:
	GameManager();
	~GameManager();

	void SetPage(Pages page);
	void StartGame();
	void SetTutorialPage();
	void SetMainPage();
	void SetMainMenu();
	void SetSubMenu();
	void SetShopPage();
};