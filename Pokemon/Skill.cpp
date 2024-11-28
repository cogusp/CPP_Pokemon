#include "Skill.h"

Skill::Skill(const std::string& n, const std::string& a, const int atk)
	:name(n), att(a), atk(atk) {}

std::string Skill::GetName() const
{
	return name;
}

std::string Skill::GetAtt() const
{
	return att;
}

int Skill::GetAtk() const
{
	return atk;
}

void Skill::SetAtk(int atk)
{
	this->atk = atk;
}
