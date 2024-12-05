#pragma once
#include "Pokemon.h"
#include "Player.h"
#include "Render.h"
#include <iostream>

class NPC
{
private:
	Pokemon* nPokemon;
	Render* nRender;

public:
	NPC();
	~NPC();

	std::string GetPName();
	int GetPHP();
	int GetPLevel();
	Pokemon* GetPokemon();

	void State(Player* p)const;
	void Script(Player* p)const;
	void SetPokemon(Pokemon& p);
};