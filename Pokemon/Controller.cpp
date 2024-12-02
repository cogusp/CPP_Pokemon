#include "Controller.h"

Controller::Controller()
{
	mRender = new Render();
}

Controller::~Controller()
{
	delete mRender;
	
	mRender = nullptr;
}

int Controller::KeyControl()
{
	if (_kbhit)						// 키보드 입력 확인
	{
		char c = _getch();

		if (c == -32)
		{
			c = _getch();

			switch (c)
			{
			case UP:
				return UP;
				break;
			case DOWN:
				return DOWN;
				break;
			case LEFT:
				return LEFT;
				break;
			case RIGHT:
				return RIGHT;
				break;
			}
		}
		else if (c == SPACE)
		{
			return SPACE;
		}
	}
}

void Controller::Move()
{
	while (true)
	{
		switch (KeyControl())	// 키 입력
		{
		case UP:
			mRender->DrawPlayer(0, -1);	// y축으로 -1 이동
			break;
		case DOWN:
			mRender->DrawPlayer(0, 1);	// y축으로 1 이동
			break;
		case RIGHT:
			mRender->DrawPlayer(1, 0);	// x축으로 1 이동
			break;
		case LEFT:
			mRender->DrawPlayer(-1, 0);	// x축으로 -1 이동
			break;
		}
	}
}