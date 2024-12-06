#pragma once
//#include "Skill.h"
#include <vector>
#include <iostream>
#include <windows.h>

class Pokemon
{
private:
	std::string name;
	int hp;
	int level;
	std::string skill1;
	int atk1;
	std::string skill2;
	int atk2;
	int saveHP;

public:
	Pokemon();
	Pokemon(const std::string& n, int h, int l, const std::string& s1, const int& a1, const std::string&s2, const int& a2);

	std::string GetName()const;
	void SetName(const std::string& n);
	int GetHP()const;
	void SetHP(int h);
	int GetLevel()const;
	void SetLevel(const int& l);
	void SetSkill(const std::string& s1, const std::string& s2);
	void SetAtk(const int& a1, const int& a2);
	std::string GetSkill1()const;
	std::string GetSkill2()const;
	int GetAtk1()const;
	int GetAtk2()const;
	int GetSaveHP()const;

	void Attack(int skill);
	void ShowPokemon(Pokemon p) const;
};