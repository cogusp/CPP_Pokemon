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
			case DOWN:
				return DOWN;
			case LEFT:
				return LEFT;
			case RIGHT:
				return RIGHT;
			}
		}
		else if (c == SPACE)
			return SPACE;
		else if (c == ESC)
			return ESC;
	}
}

void Controller::Move()
{
	while (true)
	{
		switch (KeyControl())	// Ű �Է�
		{
		case UP:
			mRender->DrawMovePlayer(0, -1);	// y������ -1 �̵�
			break;
		case DOWN:
			mRender->DrawMovePlayer(0, 1);	// y������ 1 �̵�
			break;
		case RIGHT:
			mRender->DrawMovePlayer(1, 0);	// x������ 1 �̵�
			break;
		case LEFT:
			mRender->DrawMovePlayer(-1, 0);	// x������ -1 �̵�
			break;
		}
	}
}