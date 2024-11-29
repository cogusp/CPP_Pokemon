#include "Player.h"

Player::Player() : name("")
{
}

Player::~Player()
{
}

void Player::SetName(const std::string& n)
{
	name = n;
}

std::string Player::GetName()
{
	return name;
}

void Player::SellItem(const int itemNum, int& coin)
{
	//mInven.SellItem(itemNum, coin);
}

void Player::UseItem(const int num)
{
	//mInven.UseItem(num);
}

void Player::AddItemToInven(const Item& item)
{
	//mInven.AddItem(item);
}

void Player::ShowIven() const
{
	//mInven.ShowInven();
}