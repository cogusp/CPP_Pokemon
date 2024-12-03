#include "Player.h"

Player::Player() : name("")
{
	coin = 1000;
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

void Player::SetCoin(const int& n)
{
	coin = n;
}

int Player::GetCoin()
{
	return coin;
}

void Player::SellItem()
{
	SetCoin(mInven.SellItem(coin));
}

void Player::UseItem()
{
	mInven.UseItem();
}

void Player::AddItemToInven(const Item& item)
{
	mInven.AddItem(item);
}

void Player::ShowIven() const
{
	mInven.ShowInven();
}