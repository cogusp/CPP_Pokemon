#pragma once
#include "Item.h"
#include <vector>

class Inventory
{
private:
	std::vector<Item> items;

public:
	Inventory();
	~Inventory();

	void ShowInven()const;
	void AddItem(const Item& item);
	int SellItem(int& coin);
	void UseItem();
	//void SubMenu();
};

