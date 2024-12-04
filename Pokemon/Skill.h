#pragma once
#include <iostream>

class Skill
{
private:
	std::string name;
	int atk;

public:
	Skill(const std::string& n, const int& atk);

	std::string GetName()const;
	int GetAtk()const;
	void SetAtk(int atk);
};

