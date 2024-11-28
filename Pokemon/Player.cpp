#include "Player.h"

Player::Player()
{
	
}

Player::~Player()
{
}

void Player::SellItem(const int itemNum, int& coin)
{
	mInven.SellItem(itemNum, coin);
}

void Player::UseItem(const int num)
{
	mInven.UseItem(num);
}

void Player::AddItemToInven(const Item& item)
{
	mInven.AddItem(item);
}

void Player::ShowIven() const
{
	mInven.ShowInven();
}

void Player::Move()
{
}