#include "Render.h"

// Main Page
char map[MAP_HEIGHT][MAP_WIDTH + 1] = {
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################",
	"#######################################################"
};

Render::Render()
{
	sPosition = new Position();
	temp = ' ';
	isFirst = true;
}

Render::~Render()
{
	delete sPosition;
}

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

char Render::GetCurrnetMap()
{
	return map[sPosition->y][sPosition->x];
}

Position Render::GetPlayerPos()
{
	return *sPosition;
}

void Render::DrawPlayer(int x, int y)
{
	int newX = sPosition->x + x;
	int newY = sPosition->y + y;

	// 맵을 벗어나지 못하도록 설정
	if (newY < 0 || newY >= 20 || newX < 0 || newX >= 29) return;

	// 이전 맵 다시 그리기
	if (!isFirst)
	{
		Gotoxy(sPosition->x * 2, sPosition->y);
		Draw(temp);
	}

	// 새로운 위치
	temp = map[newY][newX];
	sPosition->x = newX;
	sPosition->y = newY;

	// 플레이어 출력
	Gotoxy(newX * 2, newY);
	std::cout << "^^";

	isFirst = false;
}

void Render::DrawMap()
{
	system("cls");

	for (int h = 0; h < MAP_HEIGHT; ++h)
	{
		for (int w = 0; w <= MAP_WIDTH; ++w)
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
		std::cout << "■";
	else if (ch == 'b')
		std::cout << "  ";
	else if (ch == 's')
		std::cout << "  ";
	else if (ch == 'c')
		std::cout << "  ";
	else if(ch =='#')
		std::cout << "■"; // 벽
	else if (ch == '~')
		std::cout << "≈"; // 물
	else
		std::cout << "  ";
}
