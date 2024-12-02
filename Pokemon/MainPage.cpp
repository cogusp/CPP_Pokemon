#include "MainPage.h"

MainPage::MainPage()
{
	mRender = new Render();
	mRender->Init();
	isPlay = 0;
}

MainPage::~MainPage()
{
	delete mRender;
	mRender = nullptr;
}

int MainPage::GameLoop()
{
	mRender->DrawMap();

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
			}

			if (mRender->GetCurrnetMap() == 's')
			{
				isPlay = 1;
			}
		}
	}

	return isPlay;
}
