#include "Controller.h"

Controller::Controller()
{
	Init();
}

void Controller::Init()
{
	system("mode con cols = 56 lines = 20 | title 포키몽");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	// 콘솔 핸들 가져오기
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;		// 커서 숨기기
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void Controller::Gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	// 콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
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


