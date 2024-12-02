#include "MainPage.h"

MainPage::MainPage()
{
	mRender = new Render();
}

MainPage::~MainPage()
{
	delete mRender;
	mRender = nullptr;
}

int MainPage::GameLoop()
{
	int x, y;

	mRender->DrawMap();
	mRender->DrawPlayer();

	while (isPlay == 0)
	{
		if (KeyControl())
		{
			Move(&x, &y);
		}
	}

	return 0;
}
