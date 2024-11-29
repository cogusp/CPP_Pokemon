#pragma once
#include "Skill.h"
#include <iostream>

class Pokemon
{
private:
	std::string name;
	std::string att;
	int health;
	int level;
	Skill* skill;

public:
	Pokemon(const std::string& n, const std::string& a, const int h, const int l, Skill* s);

	void Attack();
};