#pragma once
#include "Pokemon.h"
#include "Player.h"
#include "NPC.h"

#include "Render.h"
#include "Controller.h"
#include "SubMenu.h"

#include <vector>
#include <iostream>
#include <Windows.h>

class LabPage : public Controller
{
private:
	Render* mRender;
	SubMenu* mSubMenu;
	Player* mPlayer;
	NPC* mNpc;
	Pokemon mPokemon;

	std::vector<Pokemon> pokemons;

	int x;
	int y;

public:
	LabPage();
	~LabPage();

	int isPlay = 0;
	bool isChoice = false;

	void AddPokemon(const std::string& n, int h, int l, const std::string& s1, const int& a1, const std::string& s2, const int& a2);
	void ShowPokemon(int num) const;
	int GameLoop();

	void SetPlayer(Player* p);
	void SetNPC(NPC* n);
	void SetMap();

	void SelectPokemon(int num);

	void SelectSubMenu();
};
