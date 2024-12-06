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

void Player::SetPokemon(Pokemon& p)
{
	mPokemon.SetName(p.GetName());
	mPokemon.SetHP(p.GetHP());
	mPokemon.SetLevel(p.GetLevel()); 
	mPokemon.SetSkill(p.GetSkill1(), p.GetSkill2());
	mPokemon.SetAtk(p.GetAtk1(), p.GetAtk2());
}

std::string Player::GetPName()
{
	return mPokemon.GetName();
}

void Player::SetHP(int h)
{
	mPokemon.SetHP(h);
}

int Player::GetPHP()
{
	return mPokemon.GetHP();
}

int Player::GetPLevel()
{
	return mPokemon.GetLevel();
}

std::string Player::GetPSkill1()
{
	return mPokemon.GetSkill1();
}

int Player::GetPAtk1()
{
	return mPokemon.GetAtk1();
}

std::string Player::GetPSkill2()
{
	return mPokemon.GetSkill2();
}

int Player::GetPAtk2()
{
	return mPokemon.GetAtk2();
}

int Player::GetSaveHP()
{
	return mPokemon.GetSaveHP();
}

void Player::SellItem()
{
	if (mInven.SellItem(coin) == 0)
		return;

	std::cout << "가진 금액: " << coin;
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