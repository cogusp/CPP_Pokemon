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
	if (_kbhit)						// Ű���� �Է� Ȯ��
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
		switch (KeyControl())	// Ű �Է�
		{
		case UP:
			mRender->DrawPlayer(0, -1);	// y������ -1 �̵�
			break;
		case DOWN:
			mRender->DrawPlayer(0, 1);	// y������ 1 �̵�
			break;
		case RIGHT:
			mRender->DrawPlayer(1, 0);	// x������ 1 �̵�
			break;
		case LEFT:
			mRender->DrawPlayer(-1, 0);	// x������ -1 �̵�
			break;
		}
	}
}