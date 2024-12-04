#include "LabPage.h"

LabPage::LabPage()
{
	mRender = new Render();
	mSubMenu = new SubMenu();

	mRender->Init();

	x = MAP_WIDTH / 2;
	y = MAP_HEIGHT - 2;

	AddPokemon("이상해씨", 20, 5);
	AddPokemon("꼬부기", 20, 5);
	AddPokemon("파이리", 20, 5);
}

LabPage::~LabPage()
{
	delete mRender;
	delete mSubMenu;

	mRender = nullptr;
	mSubMenu = nullptr;
}

void LabPage::AddPokemon(const std::string& n, const int& h, const int& l)
{
	pokemons.push_back(Pokemon(n, h, l));
}

void LabPage::ShowPokemon(int num) const
{
	system("cls");

	mRender->Gotoxy(MAP_HEIGHT / 2, MAP_WIDTH + 15);
	mPokemon.ShowPokemon(pokemons[num]);


}

int LabPage::GameLoop()
{
	mRender->SetPlayerPos(x, y);
	mRender->SetIsBuildZero();
	isPlay = 0;

	SetMap();
	mRender->DrawMap();
	mRender->DrawPlayer();

	while (isPlay == 0)
	{
		if (KeyControl() != 0)
		{
			switch (KeyControl())
			{
			case UP:
				mRender->DrawMovePlayer(0, -1);
				break;
			case DOWN:
				mRender->DrawMovePlayer(0, 1);
				break;
			case RIGHT:
				mRender->DrawMovePlayer(1, 0);
				break;
			case LEFT:
				mRender->DrawMovePlayer(-1, 0);
				break;
			case ESC:
				SelectSubMenu();
				break;
			}

			// Shop
			if (mRender->GetIsBuild() == 'd')
				isPlay = 1;
			if (mRender->GetIsBuild() == 'L')
				SelectPokemon(0);
			if (mRender->GetIsBuild() == 'G')
				SelectPokemon(1);
			if (mRender->GetIsBuild() == 'P')
				SelectPokemon(2);
		}
	}

	x = mRender->GetPlayerPosX();
	y = mRender->GetPlayerPosY();

	return isPlay;
}

void LabPage::SetMap()
{
	char map[MAP_HEIGHT][MAP_WIDTH + 1] = {
		"#######################################################",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#222222222222222222222222222222L2G2P22222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"##########################d############################"
	};


	mRender->SetMap(map);
}

void LabPage::SelectPokemon(int num)
{
	// Show
	ShowPokemon(num);

	// Select
}

void LabPage::SelectSubMenu()
{
	switch (mSubMenu->SelectMenu())
	{
	case 0:
		// 포켓몬
		break;
	case 1:
		// 인벤토리(가방)
		break;
	case 2:
		mRender->DrawMap();
		mRender->DrawPlayer();
		break;
	case 3:
		// 끈다
		exit(0);
		break;
	}
}