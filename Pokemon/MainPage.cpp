#include "MainPage.h"

MainPage::MainPage()
{
	mRender = new Render();
	mSubMenu = new SubMenu();

	mRender->Init();
	isPlay = 0;
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
	mRender->DrawMap();
	mRender->DrawPlayer(0, 0);

	while (isPlay == 0)
	{
		if (KeyControl() != 0)
		{
			switch (KeyControl())
			{
			case UP:
				mRender->DrawPlayer(0, -1);
				break;
			case DOWN:
				mRender->DrawPlayer(0, 1);
				break;
			case RIGHT:
				mRender->DrawPlayer(1, 0);
				break;
			case LEFT:
				mRender->DrawPlayer(-1, 0);
				break;
			case ESC:
				mSubMenu->SelectMenu();
				break;
			}

			isPlay = mRender->GetCurrnetMap();
		}
	}

	return isPlay;
}
