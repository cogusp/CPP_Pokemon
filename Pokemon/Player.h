#pragma once
#include "Inventory.h"
#include "Pokemon.h"
#include <iostream>

class Player
{
private:
	std::string name;
	int coin;
	Inventory mInven;
	Pokemon mPokemon;

public:
	Player();
	~Player();

	void SetName(const std::string& n);
	std::string GetName();
	void SetCoin(const int& n);
	int GetCoin();

	void SellItem();
	void UseItem();
	void AddItemToInven(const Item& item);
	void ShowIven()const;
};

