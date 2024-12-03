#include "GameManager.h"

GameManager::GameManager()
{
	mPlayer = new Player();
	mShop = new Shop();
	mMainMenu = new MainMenu();
	mTutorial = new TutorialPage();
	mMain = new MainPage();
	mPage = Pages::MAIN_MENU;
}

GameManager::~GameManager()
{
	delete mPlayer;
	delete mShop;
	delete mMainMenu;
	delete mTutorial;
	delete mMain;

	mPlayer = nullptr;
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
		system("cls");

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
		case Pages::SHOP:
			SetShopPage();
			break;
		case Pages::INVENTORY:
			SetInven();
			break;
		case Pages::SELL_INVENTORY:
			SetSellInven();
			break;
		default:
			std::cout << "Page Error" << std::endl;
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
		exit(0);
		break;
	default:
		std::cout << "SetMainMenu Error" << std::endl;
		break;
	}
}

void GameManager::SetShopPage()
{
	bool inShop = true;

	while (inShop)
	{
		switch (mShop->SelectMenu())
		{
		case 1:
			mShop->BuyItem(mPlayer);
			break;
		case 2:
			SetPage(Pages::SELL_INVENTORY);
			break;
		case 3:
			inShop = false;
			break;
		}
	}

	SetPage(Pages::MAIN_PAGE);
}

void GameManager::SetInven()
{
	mPlayer->ShowIven();
}

void GameManager::SetSellInven()
{
	mPlayer->SellItem();
}