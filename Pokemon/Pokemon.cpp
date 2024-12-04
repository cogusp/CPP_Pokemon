#include "Pokemon.h"

Pokemon::Pokemon()
{
}

Pokemon::Pokemon(const std::string& n, const int& h, const int& l)
	: name(n), hp(h), level(l)
{
}

void Pokemon::AddSkill(const std::string& n, const int& a)
{
	skills.push_back(Skill(n, a));
}

void Pokemon::Attack()
{
}

void Pokemon::ShowPokemon(Pokemon p) const
{
	std::cout << p.name << ", " << p.hp << ", " << p.level << std::endl;
}