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
		switch (KeyControl())	// Ű �Է�
		{
		case UP:
			Move(&x, &y, 0, -1);	// y������ -1 �̵�
			break;
		case DOWN:
			Move(&x, &y, 0, 1);		// y������ 1 �̵�
			break;
		case RIGHT:
			Move(&x, &y, 1, 0);		// x������ 1 �̵�
			break;
		case LEFT:
			Move(&x, &y, -1, 0);	// x������ -1 �̵�
			break;
		}
	}
}

// �÷��̾� ��ǥ ����
// ��ǥ x, ��ǥ y, �̵� �� x, �̵� �� y
void MainPage::Move(int* x, int* y, int _x, int _y)
{
	Gotoxy(*x, *y);
	std::cout << "  ";			// �����

	Gotoxy(*x + _x, *y + _y);	// ������ ��ġ�� �̵� �� �÷��̾� ���
	std::cout << "P";

	// ���� ��ǥ �� ����
	*x += _x;
	*y += _y;
}

void MainPage::Draw(int*, int*)
{
	//mMap->DrawMap();
}
