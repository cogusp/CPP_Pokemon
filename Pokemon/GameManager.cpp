#include "GameManager.h"

GameManager::GameManager()
{
	//mPlayer = new Player();
	mShop = new Shop();
	mMainMenu = new MainMenu();
	mTutorial = new TutorialPage();
	mMain = new MainPage();

	mPage = Pages::MAIN_MENU;
	//mCoin = 1000;
}

GameManager::~GameManager()
{
	//delete mPlayer;
	delete mShop;
	delete mMainMenu;
	delete mTutorial;
	delete mMain;
	 
	//mPlayer = nullptr;
	mShop = nullptr;
	mMainMenu = nullptr;
	mTutorial = nullptr;
	mMain = nullptr;
}

void GameManager::SetPage(Pages page)
{
	mPage = page;
}

void GameManager::StartGame()
{
	bool isStart = true;

	while (isStart)
	{
		switch (mPage)
		{
		case Pages::MAIN_MENU:
			SetMainMenu();
			break;
		case Pages::TUTORIAL_PAGE:
			SetTutorialPage();
			break;
		case Pages::MAIN_PAGE:
			SetMainPage();
			break;
		case Pages::SUB_MENU:
			SetSubMenu();
			break;
		case Pages::SHOP:
			SetShopPage();
			break;
		default:
			std::cout << "위치 에러" << std::endl;
			isStart = false;
			break;
		}
	}
}

void GameManager::SetTutorialPage()
{
	mTutorial->ShowGameInfo();
	SetPage(Pages::MAIN_PAGE);
}

void GameManager::SetMainPage()
{
	switch (mMain->GameLoop())
	{
	case 1:
		SetPage(Pages::SHOP);
		break;
	case 2:
		break;
	}
}

void GameManager::SetMainMenu()
{
	switch (mMainMenu->SelectMenu())
	{
	case 0:
		SetPage(Pages::TUTORIAL_PAGE);
		break;
	case 1:
		SetPage(Pages::MAIN_PAGE);
		break;
	case 2:
		exit(0);
		break;
	default:
		std::cout << "SetMainMenu Error" << std::endl;
		break;
	}	 
}

void GameManager::SetSubMenu()
{
}

void GameManager::SetShopPage()
{
	//int select;

	//std::cout << "상점" << std::endl;
	//
	//// 옮기자
	//mShop->ShowItems();
	//std::cout << "구매할 아이템 번호: ";
	//std::cin >> select;

	//mShop->BuyItem(select - 1, mCoin);

	//SetPage(Pages::INVENTORY);

	system("cls");
	mShop->ShowItems();
}