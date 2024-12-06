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

	void SetPokemon(Pokemon &p);
	std::string GetPName();
	void SetHP(int h);
	int GetPHP();
	int GetPLevel();
	std::string GetPSkill1();
	int GetPAtk1();
	std::string GetPSkill2();
	int GetPAtk2();
	int GetSaveHP();

	void SellItem();
	void UseItem();
	void AddItemToInven(const Item& item);
	void ShowIven()const;
};

