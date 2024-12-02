#include "Render.h"

void Render::Init()
{
	system("mode con: cols=110 lines=40 | title 포키몽");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	// 콘솔 핸들 가져오기
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;								// 커서 숨기기
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void Render::Gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	// 콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void Render::DrawPlayer(int x, int y)
{
	if (y < 0 || y >= 20) return;
	else if (x < 0 || x >= 29) return;

	char temp;

	if (!isFirst)
	{
		Gotoxy(x, y);
		Draw(temp);
	}

	temp = map[y][x];

	sPosition->x += x;
	sPosition->y += y;

	Gotoxy(x, y);
	std::cout << "^^";
}

// Main Page
char map[20][29] = {
	//{"1111111111102222011111111111"},
	//{"1111111111102222011111111111"},
	//{"1111111111102222011111111111"},
	//{"1111111111102222011111111111"},
	//{"1111111111102222011111111111"},
	//{"0000000000002222000000000000"},
	//{"2222222222222222222222222222"},
	//{"2222222222222222222222222222"},
	//{"2222222222222222222222222222"},
	//{"02BBB222BBB222222BBB222BBB22"},
	//{"02BbB222BbB222222BcB222BsB22"},
	//{"2222222222222222222222222222"},
	//{"2222222222222222222222222222"},
	//{"2222222222222222222222222222"},
	//{"22BBB222BBB222222BBB222BBB22"},
	//{"22BbB222BbB222222BbB222BbB22"},
	//{"2222222222222222222222222222"},
	//{"2222222222222222222222222222"},
	//{"2222222222222222222222222222"},
	//{"2222222222222222222222222222"},

	{"1111111111111111111111111111"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"122222222222222222222s222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1222222222222222222222222221"},
	{"1111111111111111111111111111"},
};

void Render::DrawMap()
{
	system("cls");

	for (int h = 0; h < 20; ++h)
	{
		for (int w = 0; w < 29; ++w)
		{
			Draw(map[h][w]);
		}
		std::cout << std::endl;
	}
}

void Render::Draw(char ch)
{
	if (ch == '0')
		std::cout << "●";
	else if (ch == '1')
		std::cout << "**";
	else if (ch == '2')
		std::cout << "  ";
	else if (ch == 'B')
		std::cout << "◼";
	else if (ch == 'b')
		std::cout << "  ";
	else if (ch == 's')
		std::cout << "++";
	else if (ch == 'c')
		std::cout << "  ";
}
