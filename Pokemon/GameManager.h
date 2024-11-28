#pragma once
#include "Player.h"
#include "Shop.h"
#include <iostream>

class GameManager
{
private:
	enum class Pages
	{
		TUTORIAL_PAGE = 1,
		MAIN_PAGE,
		MAIN_MENU,
		SUB_MENU,
		INVENTORY,
		SHOP,
		SELL_INVENTORY,
	};

	Player* mPlayer;
	Shop* mShop;
	Pages mPage;
	int mCoin;
	int mSelect;

public:
	GameManager();
	~GameManager();

	void SetPage(Pages page);
	void StartGame();
	void SetTutorialPage();
	void SetMainPage();
	void SetMainMenu();
	void SetSubMenu();
	void SetInventoryPage();
	void SetShopPage();
	void SetSellInventoryPage();

	void ShowShopitems();
	void BuyItem(int num);
	void UseItem(const int num);
};