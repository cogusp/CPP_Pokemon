#include "Controller.h"

Controller::Controller()
{
	mMap = new Render();
}

Controller::~Controller()
{
	delete mMap;

	mMap = nullptr;
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

void Controller::Move(int* x, int* y)
{
	while (true)
	{
		switch (KeyControl())	// 키 입력
		{
		case UP:
			y -= 1;	// y축으로 -1 이동
			break;
		case DOWN:
			y += 1;	// y축으로 1 이동
			break;
		case RIGHT:
			x += 1;	// x축으로 1 이동
			break;
		case LEFT:
			x -= 1;	// x축으로 -1 이동
			break;
		}
	}
}