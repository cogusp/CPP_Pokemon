#include "Controller.h"

Controller::Controller()
{
	Init();
}

void Controller::Init()
{
	system("mode con cols = 56 lines = 20 | title ��Ű��");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	// �ܼ� �ڵ� ��������
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;		// Ŀ�� �����
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void Controller::Gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	// �ܼ� �ڵ� ��������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
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


