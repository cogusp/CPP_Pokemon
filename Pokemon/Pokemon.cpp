#include "Pokemon.h"

Pokemon::Pokemon(const std::string& n, const std::string& a, const int h, const int l, Skill* s)
	: name(n), att(a), health(h), level(l), skill(s)
{
}