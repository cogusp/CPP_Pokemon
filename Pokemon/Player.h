#pragma once
#include "Inventory.h"
#include <iostream>

class Player
{
private:
	std::string name;
	//int coin;
	//Inventory mInven;

public:
	Player();
	~Player();

	void SetName(const std::string& n);
	std::string GetName();

	void SellItem(const int itemNum, int& coin);
	void UseItem(const int num);
	void AddItemToInven(const Item& item);
	void ShowIven()const;
};

