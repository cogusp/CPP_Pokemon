#include "Render.h"

char pMap[MAP_HEIGHT][MAP_WIDTH + 1] = {
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
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
		"#22222222222222222222222222222222222222222222222222222#",
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
	map[0][0] = { ' ' };
	isBuild = ' ';
	temp = ' ';
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

void Render::SetMap(char arr[][MAP_WIDTH + 1])
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			map[i][j] = arr[i][j];
		}
	}
}

void Render::SetIsBuildZero()
{
	isBuild = ' ';
}

char Render::GetIsBuild()
{
	return isBuild;
}

void Render::SetPlayerPos(int x, int y)
{
	sPosition->x = x;
	sPosition->y = y;
}

int Render::GetPlayerPosX()
{
	return sPosition->x;
}

int Render::GetPlayerPosY()
{
	return sPosition->y;
}

void Render::DrawPlayer()
{
	// 이동할 곳의 데이터 저장
	temp = map[sPosition->y][sPosition->x];

	// 플레이어 출력
	Gotoxy(sPosition->x * 2, sPosition->y);
	std::cout << "¡";
}

void Render::DrawMovePlayer(int x, int y)
{
	int newX = sPosition->x + x;
	int newY = sPosition->y + y;

	// 맵을 벗어나지 않도록 설정
	if (newY < 0 || newY >= MAP_HEIGHT || newX < 0 || newX >= MAP_WIDTH || 
		map[newY][newX] == '#')
		return;

	if (map[newY][newX] == 's' || map[newY][newX] == 'c' || 
		map[newY][newX] == 'l' || map[newY][newX] == 'd' ||
		map[newY][newX] == 'n' || map[newY][newX] == 'L' ||
		map[newY][newX] == 'G' || map[newY][newX] == 'P')
	{
		isBuild = map[newY][newX];
		return;
	}

	// 이전 맵 다시 그리기
	Gotoxy(sPosition->x * 2, sPosition->y);
	Draw(temp);

	// 새로운 위치 설정
	SetPlayerPos(newX, newY);

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

void Render::DrawPokemon()
{
	system("cls");

	for (int h = 0; h < MAP_HEIGHT; ++h)
	{
		for (int w = 0; w <= MAP_WIDTH; ++w)
		{
			Draw(pMap[h][w]);
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
	else if (ch == 'L' || ch == 'G' || ch == 'P')
		std::cout << "●";
	else if (ch == 'b')
		std::cout << "■";
	else if (ch == 'l' || ch == 's' || ch == 'c' || ch == 'd')
		std::cout << "▥";
	else if (ch == '#')
		std::cout << "■";
	else
		std::cout << ch << " ";
}