#pragma once
#include <iostream>

class Skill
{
private:
	std::string name;
	std::string att;
	int atk;

public:
	Skill(const std::string& n, const std::string& a, const int atk);

	std::string GetName()const;
	std::string GetAtt()const;
	int GetAtk()const;
	void SetAtk(int atk);
};

