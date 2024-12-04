#include "Skill.h"

Skill::Skill(const std::string& n, const int& atk)
	:name(n), atk(atk) {}

std::string Skill::GetName() const
{
	return name;
}

int Skill::GetAtk() const
{
	return atk;
}

void Skill::SetAtk(int atk)
{
	this->atk = atk;
}
