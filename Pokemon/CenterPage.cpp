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
		// ���ϸ�
		break;
	case 1:
		// �κ��丮(����)
		break;
	case 2:
		mRender->DrawMap();
		mRender->DrawPlayer();
		break;
	case 3:
		// ����
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
	std::cout << "���ϸ����Դϴ�!" << std::endl;
	mRender->Gotoxy(_x, _y - 5);
	std::cout << "���ϸ��� ġ���Ͻðھ��?" << std::endl;

	mRender->Gotoxy(_x - 2, _y);
	std::cout << "> ��" << std::endl;
	mRender->Gotoxy(_x, _y + 1);
	std::cout << "�ƴϿ�" << std::endl;

	while (select == -1)
	{
		int key = KeyControl(); // Ű���� �̺�Ʈ �Է� ��

		switch (key)
		{
		case UP:
			if (_y > (MAP_HEIGHT / 2 + 5)) // y�� �̵� ����
			{
				mRender->Gotoxy(_x - 2, _y);
				std::cout << " ";
				mRender->Gotoxy(_x - 2, --_y);
				std::cout << ">";
			}
			break;
		case DOWN:
			if (_y < (MAP_HEIGHT / 2 + 6)) // y�� �̵� ����
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

	system("cls"); // �ܼ�â �ʱ�ȭ

	if (select == 0)
	{
		p->SetHP(p->GetSaveHP());

		mRender->Gotoxy(10, 10);
		std::cout << "���ϸ��� ġ���߽��ϴ�!";
		Sleep(2000);
	}

	// �ʰ� �÷��̾� �ʱ� ��ġ �缳��
	mRender->Init();
	SetMap();
	mRender->DrawMap();

	// ���� ��ġ�� �÷��̾� ����
	mRender->SetPlayerPos(x, y);
	mRender->DrawPlayer();

	// ���� ���� �����
	GameLoop(p);
}
