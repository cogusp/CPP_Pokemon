#include "LabPage.h"

LabPage::LabPage()
{
	mRender = new Render();
	mSubMenu = new SubMenu();

	mRender->Init();

	x = MAP_WIDTH / 2;
	y = MAP_HEIGHT - 2;

	AddPokemon("이상해씨", 45, 5, "덩쿨채찍", 5, "울음소리", 3);
	AddPokemon("꼬부기", 44, 5, "물대포", 6, "울음소리", 3);
	AddPokemon("파이리", 39, 5, "화염방사", 7, "울음소리", 3);
}

LabPage::~LabPage()
{
	delete mRender;
	delete mSubMenu;
	delete mPlayer;
	delete mNpc;

	mRender = nullptr;
	mSubMenu = nullptr;
	mPlayer = nullptr;
	mNpc = nullptr;
}

void LabPage::AddPokemon(const std::string& n, int h, int l, const std::string& s1, const int& a1, const std::string& s2, const int& a2)
{
	pokemons.push_back(Pokemon(n, h, l, s1, a1, s2, a2));
}

void LabPage::ShowPokemon(int num) const
{
	system("cls");

	mRender->Gotoxy(0, 1);
	
	if (num == 0)
		mRender->DrawL();
	else if (num == 1)
		mRender->DrawG();
	else if (num == 2)
		mRender->DrawP();

	mRender->Gotoxy(MAP_WIDTH, MAP_HEIGHT / 3);
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
			if (!isChoice)
			{
				if (mRender->GetIsBuild() == 'L')
					SelectPokemon(0);
				if (mRender->GetIsBuild() == 'G')
					SelectPokemon(1);
				if (mRender->GetIsBuild() == 'P')
					SelectPokemon(2);
			}
		}
	}

	x = mRender->GetPlayerPosX();
	y = mRender->GetPlayerPosY();

	return isPlay;
}

void LabPage::SetPlayer(Player* p)
{
	mPlayer = p;
}

void LabPage::SetNPC(NPC* n)
{
	mNpc = n;
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
		"#222222222222222222n222@@@@@@@@@2222222222222222222222#",
		"#2222222222222222222222@L@@G@@P@2222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"##########################dd###########################"
	};


	mRender->SetMap(map);
}

void LabPage::SelectPokemon(int num)
{
	x = mRender->GetPlayerPosX();
	y = mRender->GetPlayerPosY();

	// Show
	ShowPokemon(num);

	// Select
	int _x = MAP_WIDTH;
	int _y = MAP_HEIGHT / 2 + 5;

	int select = -1;

	mRender->Gotoxy(_x, _y - 6);
	std::cout << "그래!" << std::endl;
	mRender->Gotoxy(_x, _y - 5);
	std::cout << pokemons[num].GetName() << "를 갖고싶니?" << std::endl;

	mRender->Gotoxy(_x - 2, _y);
	std::cout << "> 예" << std::endl;
	mRender->Gotoxy(_x, _y + 1);
	std::cout << "아니오" << std::endl;

	while (select == -1)
	{
		int key = KeyControl(); // 키보드 이벤트 입력 값

		switch (key)
		{
		case UP:
			if (_y > (MAP_HEIGHT / 2 + 5)) // y축 이동 범위
			{
				mRender->Gotoxy(_x - 2, _y);
				std::cout << " ";
				mRender->Gotoxy(_x - 2, --_y);
				std::cout << ">";
			}
			break;
		case DOWN:
			if (_y < (MAP_HEIGHT / 2 + 6)) // y축 이동 범위
			{
				mRender->Gotoxy(_x - 2, _y);
				std::cout << " ";
				mRender->Gotoxy(_x - 2, ++_y);
				std::cout << ">";
			}
			break;
		case SPACE:
			select = _y - (MAP_HEIGHT / 2 + 5);
			break;
		}
	}

	system("cls"); // 콘솔창 초기화

	if (select == 0)
	{
		mPlayer->SetPokemon(pokemons[num]);
		isChoice = true;

		switch (num)
		{
		case 0:
			mNpc->SetPokemon(pokemons[1]);
			break;
		case 1:
			mNpc->SetPokemon(pokemons[2]);
			break;
		case 2:
			mNpc->SetPokemon(pokemons[0]);
			break;
		}

		mRender->Gotoxy(10, 10);
		std::cout << mPlayer->GetPName() <<"를 선택했다!";
		Sleep(2000);
	}

	// 맵과 플레이어 초기 위치 재설정
	mRender->Init();
	SetMap();
	mRender->DrawMap();

	// 이전 위치로 플레이어 생성
	mRender->SetPlayerPos(x, y);
	mRender->DrawPlayer();

	// 게임 루프 재실행
	GameLoop();
}

void LabPage::SelectSubMenu()
{
	mSubMenu->Menu(mPlayer);

	GameLoop();
}