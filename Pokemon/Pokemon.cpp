#include "Pokemon.h"

Pokemon::Pokemon()
{
}

Pokemon::Pokemon(const std::string& n, int h, int l, const std::string& s1, const int& a1, const std::string& s2, const int& a2)
	: name(n), hp(h), level(l), skill1(s1), atk1(a1), skill2(s2), atk2(a2)
{
}

//void Pokemon::AddSkill(const std::string& n, const int& a)
//{
//	skills.push_back(Skill(n, a));
//}

std::string Pokemon::GetName()const
{
	return name;
}

void Pokemon::SetName(const std::string& n)
{
	name = n;
}

int Pokemon::GetHP()const
{
	return hp;
}

void Pokemon::SetHP(int h)
{
	hp = h;
}

int Pokemon::GetLevel()const
{
	return level;
}

void Pokemon::SetLevel(const int& l)
{
	level = l;
}

void Pokemon::SetSkill(const std::string& s1, const std::string& s2)
{
	skill1 = s1;
	skill2 = s2;
}

void Pokemon::SetAtk(const int& a1, const int& a2)
{
	atk1 = a1;
	atk2 = a2;
}

std::string Pokemon::GetSkill1()const
{
	return skill1;
}

std::string Pokemon::GetSkill2()const
{
	return skill2;
}

int Pokemon::GetAtk1()const
{
	return atk1;
}

int Pokemon::GetAtk2()const
{
	return atk2;
}

void Pokemon::Attack(int skill)
{
	switch (skill)
	{
	case 0:
		skill1;
		atk1;
		break;
	case 1:
		skill2;
		atk2;
		break;
	}
}

void Pokemon::ShowPokemon(Pokemon p) const
{
	std::cout << p.name << ", " << p.hp << ", " << p.level << std::endl;
}