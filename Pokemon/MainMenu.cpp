#include "MainMenu.h"

void MainMenu::MenuList()
{
	Gotoxy(x - 2, y);
	std::cout << "▶ 새로운 모험을 시작한다" << std::endl;
	Gotoxy(x, y + 1);
	std::cout << "나간다" << std::endl;
}

int MainMenu::SelectMenu()
{
	MenuList();

	while (1)
	{
		int key = KeyControl();			// 키보드 이벤트 입력 값

		switch (key)
		{
		case UP:
			if (y > 12)					// y축 이동 범위
			{
				Gotoxy(x - 2, y);		// 두 칸 이전에 > 출력
				std::cout << " ";		// 원래 위치 삭제
				Gotoxy(x - 2, --y);		// 위치 이동
				std::cout << "▶";		// 다시 그림
			}
			break;
		case DOWN:
			if (y < 13)					// y축 이동 범위
			{
				Gotoxy(x - 2, y);		// 두 칸 이전에 > 출력
				std::cout << " ";		// 원래 위치 삭제
				Gotoxy(x - 2, ++y);		// 위치 이동
				std::cout << "▶";		// 다시 그림
			}
			break;
		case SPACE:
			system("cls");		// 콘솔창의 모든 글자 비우고 좌표 0, 0 초기화
			return y - 12;
		}
	}
}