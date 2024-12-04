#pragma once
#include "Skill.h"
#include <vector>
#include <iostream>
#include <windows.h>

class Pokemon
{
private:
	std::string name;
	int hp;
	int level;
	std::vector<Skill> skills;
	

public:
	Pokemon();
	Pokemon(const std::string& n, const int& h, const int& l);
	
	void AddSkill(const std::string& n, const int& a);

	void Attack();
	void ShowPokemon(Pokemon p) const;
};