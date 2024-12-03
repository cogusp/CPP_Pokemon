#include "MainPage.h"

MainPage::MainPage()
{
	mRender = new Render();
	mSubMenu = new SubMenu();

	mRender->Init();
}

MainPage::~MainPage()
{
	delete mRender;
	delete mSubMenu;

	mRender = nullptr;
	mSubMenu = nullptr;
}

int MainPage::GameLoop()
{
	isPlay = 0;
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
				// 메뉴 닫은 후 다시 그리기
				mRender->DrawMap();
				mRender->DrawPlayer();
				break;
			}

			// Shop
			if (mRender->GetIsBuild() == 's')
			{
				isPlay = 1;
			}
		}
	}

	return isPlay;
}

void MainPage::SelectSubMenu()
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
		// 닫다
		break;
	case 3:
		// 끈다
		exit(0);
		break;
	}

}
