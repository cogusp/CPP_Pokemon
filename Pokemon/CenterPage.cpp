#include "CenterPage.h"

CenterPage::CenterPage()
{
	mRender = new Render();
	mSubMenu = new SubMenu();

	mRender->Init();

	x = MAP_WIDTH / 2;
	y = MAP_HEIGHT - 2;
}

CenterPage::~CenterPage()
{
	delete mRender;
	delete mSubMenu;

	mRender = nullptr;
	mSubMenu = nullptr;
}

int CenterPage::GameLoop(Player* p)
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
			if (mRender->GetIsBuild() == 'n')
				Heal(p);
		}
	}

	x = mRender->GetPlayerPosX();
	y = mRender->GetPlayerPosY();

	return isPlay;
}

void CenterPage::SetMap()
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
		"#22222222222222222222222222n22222222222222222222222222#",
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

void CenterPage::SelectSubMenu()
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

void CenterPage::Heal(Player* p)
{
	x = mRender->GetPlayerPosX();
	y = mRender->GetPlayerPosY();

	// Select
	int _x = MAP_WIDTH;
	int _y = MAP_HEIGHT / 2 + 5;

	int select = -1;

	mRender->Gotoxy(_x, _y - 6);
	std::cout << "포켓몬센터입니다!" << std::endl;
	mRender->Gotoxy(_x, _y - 5);
	std::cout << "포켓몬을 치료하시겠어요?" << std::endl;

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
		p->SetHP(p->GetSaveHP());

		mRender->Gotoxy(10, 10);
		std::cout << "포켓몬을 치료했습니다!";
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
	GameLoop(p);
}
