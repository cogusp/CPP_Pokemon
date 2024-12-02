#include "Item.h"

Item::Item() {}

Item::Item(const std::string& n, const std::string a, int p, int h, int c)
    : name(n), att(a), price(p), heal(h), count(c) {}

std::string Item::GetName() const
{
    return name;
}

std::string Item::GetAtt() const
{
    return att;
}

int Item::GetPrice() const
{
    return price;
}

int Item::GetHeal() const
{
    return heal;
}

int Item::GetCount() const
{
    return count;
}

void Item::SetCount(int count)
{
    this->count = count;
}
