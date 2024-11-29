#pragma once
// 중복 선언 방지를 위한 활성 전처리기 블록
//#ifndef __IOSTREAM_H__
//#define __STDIO_H__
//
//#include <iostream>
//
//
//#endif
//
//#ifndef __WINDOWS_H__
//#define __WINDOWS_H__
//
//#include <windows.h>
//
//#endif


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
	//Shop* mShop;
	
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