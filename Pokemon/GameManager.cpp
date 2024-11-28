#include "GameManager.h"

GameManager::GameManager()
{
	mPlayer = new Player();
	mShop = new Shop();
	mCoin = 1000;
	mPage = Pages::TUTORIAL_PAGE;
}

GameManager::~GameManager()
{
	delete mPlayer;
	delete mShop;
	mPlayer = nullptr;
	mShop = nullptr;
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
		case Pages::TUTORIAL_PAGE:
			SetTutorialPage();
			break;
		case Pages::MAIN_PAGE:
			SetMainPage();
			break;
		case Pages::MAIN_MENU:
			SetMainMenu();
			break;
		case Pages::SUB_MENU:
			SetSubMenu();
			break;
		case Pages::INVENTORY:
			SetInventoryPage();
			break;
		case Pages::SHOP:
			SetShopPage();
			break;
		case Pages::SELL_INVENTORY:
			SetSellInventoryPage();
			break;
		default:
			std::cout << "��ġ ����" << std::endl;
			isStart = false;
			break;
		}
	}
}

void GameManager::SetTutorialPage()
{
}

void GameManager::SetMainPage()
{
}

void GameManager::SetMainMenu()
{
}

void GameManager::SetSubMenu()
{
}

void GameManager::SetInventoryPage()
{
	std::cout << "�κ��丮" << std::endl;
	mPlayer->ShowIven();

	std::cout << "������ ������: ";
	int select;
	std::cin >> select;

	UseItem(select);
	
	/*
	
	// �Ǹ�
	SetPage(Page::SELL_INVENTORY);
	
	*/
}

void GameManager::SetShopPage()
{
	int select;

	std::cout << "����" << std::endl;
	
	// �ű���
	mShop->ShowItems();
	std::cout << "������ ������ ��ȣ: ";
	std::cin >> select;

	BuyItem(select);

	SetPage(Pages::INVENTORY);
}

void GameManager::SetSellInventoryPage()
{
	std::cout << "�Ǹ��� ������ �Է�: ";
	int num;
	std::cin >> num;

	mPlayer->SellItem(num, mCoin);
	mPlayer->ShowIven();
}

void GameManager::ShowShopitems()
{
	mShop->ShowItems();
}

void GameManager::BuyItem(int num)
{
	Item* bought = mShop->BuyItem(num - 1, mCoin);

	if (bought != nullptr)
	{
		std::cout << " ���� ����" << std::endl;
		mPlayer->AddItemToInven(*bought);
		
		mCoin -= bought->GetPrice();
	}
	else
	{
		std::cout << "���� �Ұ���" << std::endl;
	}
}

void GameManager::UseItem(const int num)
{
	mPlayer->UseItem(num);
}
