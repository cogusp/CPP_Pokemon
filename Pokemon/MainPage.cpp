#include "MainPage.h"

MainPage::MainPage()
{
	mMap = new Map();
}

MainPage::~MainPage()
{
	delete mMap;
	mMap = nullptr;
}

void MainPage::GameLoop()
{
	int x, y;

	bool isPlay = true;

	mMap->DrawMap(&x, &y);

	while (isPlay)
	{
		switch (KeyControl())	// 키 입력
		{
		case UP:
			Move(&x, &y, 0, -1);	// y축으로 -1 이동
			break;
		case DOWN:
			Move(&x, &y, 0, 1);		// y축으로 1 이동
			break;
		case RIGHT:
			Move(&x, &y, 1, 0);		// x축으로 1 이동
			break;
		case LEFT:
			Move(&x, &y, -1, 0);	// x축으로 -1 이동
			break;
		}
	}
}

// 플레이어 좌표 조작
// 좌표 x, 좌표 y, 이동 값 x, 이동 값 y
void MainPage::Move(int* x, int* y, int _x, int _y)
{
	Gotoxy(*x, *y);
	std::cout << "  ";			// 지우기

	Gotoxy(*x + _x, *y + _y);	// 증감한 위치로 이동 후 플레이어 출력
	std::cout << "P";

	// 실제 좌표 값 변경
	*x += _x;
	*y += _y;
}

void MainPage::Draw(int*, int*)
{
	//mMap->DrawMap();
}
