#include "Render.h"

// Main Page
char map[MAP_HEIGHT][MAP_WIDTH + 1] = {
	"#######################################################",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#222222222222222222222222222222222s2222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#22222222222222222222222222222222222222222222222222222#",
	"#######################################################"
};

Render::Render()
{
	sPosition = new Position();
	isBuild = ' ';
	temp = ' ';
	isFirst = true;
}

Render::~Render()
{
	delete sPosition;
}

void Render::Init()
{
	system("mode con:cols=120lines=50 | title 포키몽");

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

char Render::GetIsBuild()
{
	return isBuild;
}

Position Render::GetPlayerPos()
{
	return *sPosition;
}

void Render::DrawPlayer()
{
	// 이동할 곳의 데이터 저장
	temp = map[sPosition->y][sPosition->x];

	// 플레이어 출력
	Gotoxy(sPosition->x * 2, sPosition->y);
	std::cout << "^^";
}

void Render::DrawMovePlayer(int x, int y)
{
	int newX = sPosition->x + x;
	int newY = sPosition->y + y;

	// 맵을 벗어나지 않도록 설정
	if (newY < 0 || newY >= MAP_HEIGHT || newX < 0 || newX >= MAP_WIDTH) 
		return;

	if (map[newY][newX] == 's')
	{
		isBuild = map[newY][newX];
		return;
	}

	// 이전 맵 다시 그리기
	Gotoxy(sPosition->x * 2, sPosition->y);
	Draw(temp);

	// 새로운 위치 설정
	sPosition->x = newX;
	sPosition->y = newY;

	// 플레이어 그리기
	DrawPlayer();
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
		std::cout << "&&";
	else if (ch == 'c')
		std::cout << "  ";
	else if (ch == '#')
		std::cout << "■";
	else if (ch == '~')
		std::cout << "≈";
	else
		std::cout << "  ";
}