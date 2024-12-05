#include "MainPage.h"

MainPage::MainPage()
{
	mRender = new Render();
	mSubMenu = new SubMenu();

	mRender->Init();

	x = 25;
	y = 10;
}

MainPage::~MainPage()
{
	delete mRender;
	delete mSubMenu;

	mRender = nullptr;
	mSubMenu = nullptr;
}

int MainPage::GameLoop(Player* p)
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
				SelectSubMenu(p);				
				break;
			}
			 
			// Shop
			if (mRender->GetIsBuild() == 's')
				isPlay = 1;
			// Pokemon Center
			if (mRender->GetIsBuild() == 'c') 
				isPlay = 2;
			// Lab
			if (mRender->GetIsBuild() == 'l')
				isPlay = 3;
			// NPC
			if (mRender->GetIsBuild() == 'n')
				isPlay = 4;
		}
	}

	x = mRender->GetPlayerPosX();
	y = mRender->GetPlayerPosY();

	return isPlay;
}

void MainPage::SetMap()
{
	char map[MAP_HEIGHT][MAP_WIDTH + 1] = {
		"#######################################################",
		"#11111111111111112222222222222222222111111111111111111#",
		"#11111111111111112222222222222222222111111111111111111#",
		"#11111111111111112222222222222222222111111111111111111#",
		"#11111111111111112222222222n22222222111111111111111111#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#2222CENTER22222222222222222222222222222MARKET22222222#",
		"#2222bbbbbb2222222222222222222222222222bbbbbbbb2222222#",
		"#222bbbbbbbb222222222222222222222222222bbbbbbbb2222222#",
		"#222bbbbbbbb222222222222222222222222222bbbbbbbb2222222#",
		"#222bbbccbbb222222222222222222222222222bbbssbbb2222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222IAB222222222222222222222222222222222222222222#",
		"#222222bbbbbb22222222222222222222222222222222222222222#",
		"#222222bbbbbb22222222222222211111111111111111111111111#",
		"#222222bbllbb22222222222222211111111111111111111111111#",
		"#22222222222222222222222222211111111111111111111111111#",
		"#22222222222222222222222222211111111111111111111111111#",
		"#######################################################"
	};

	mRender->SetMap(map);
}

void MainPage::SelectSubMenu(Player* p)
{
	mSubMenu->Menu(p);

	GameLoop(p);
}
