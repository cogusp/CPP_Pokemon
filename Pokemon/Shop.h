 #pragma once
#include "Item.h"
#include "Player.h"
#include <vector>

class Shop
{
private:
	std::vector<Item> items;

public:
	Shop();
	~Shop();

	void SetItems();
	int SelectMenu();
	void ShowItems()const;
	void BuyItem(Player* mPlayer);
	void AddItem(const Item& item);
};

