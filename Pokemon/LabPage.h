#pragma once
#include "Pokemon.h"
#include "Render.h"
#include "Controller.h"
#include "SubMenu.h"
#include <vector>
#include <iostream>

class LabPage : public Controller
{
private:
	Render* mRender;
	SubMenu* mSubMenu;
	Pokemon mPokemon;

	std::vector<Pokemon> pokemons;

	int x;
	int y;

public:
	LabPage();
	~LabPage();

	int isPlay = 0;

	void AddPokemon(const std::string& n, const int& h, const int& l);
	void ShowPokemon(int num) const;
	int GameLoop();
	void SetMap();
	void SelectPokemon(int num);
	void SelectSubMenu();
};
