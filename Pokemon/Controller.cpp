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

void Controller::Move(int* x, int* y)
{
	while (true)
	{
		switch (KeyControl())	// Ű �Է�
		{
		case UP:
			y -= 1;	// y������ -1 �̵�
			break;
		case DOWN:
			y += 1;	// y������ 1 �̵�
			break;
		case RIGHT:
			x += 1;	// x������ 1 �̵�
			break;
		case LEFT:
			x -= 1;	// x������ -1 �̵�
			break;
		}
	}
}