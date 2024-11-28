#pragma once
#include <iostream>

class Item
{
private:
	std::string name;
	std::string att;
	int price;
	int heal;
	int count;

public:
	Item();
	Item(const std::string& n, const std::string a, int p, int h, int c);

	std::string GetName()const;
	std::string GetAtt()const;
	int GetPrice()const;
	int GetHeal()const;
	int GetCount()const;
	int SetCount(int count);
};

