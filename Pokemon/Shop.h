#pragma once
#include "Item.h"
#include <vector>

class Shop
{
private:
	std::vector<Item> items;

public:
	Shop();
	~Shop();

	void SetItems();
	void ShowItems()const;
	Item* BuyItem(const int index, int& coin);
	void AddItem(const Item& item);
};

