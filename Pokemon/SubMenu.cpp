#include "SubMenu.h"

void SubMenu::MenuList()
{
	Gotoxy(x - 2, y);
	std::cout << "> 포켓몬" << std::endl;
	Gotoxy(x, y + 1);
	std::cout << "가방" << std::endl;
	Gotoxy(x, y + 2);
	std::cout << "레포트" << std::endl;
    Gotoxy(x, y + 3);
    std::cout << "닫다" << std::endl;
    Gotoxy(x, y + 4);
    std::cout << "끈다" << std::endl;
}

int SubMenu::SelectMenu()
{
    MenuList();

    while (1)
    {
        int key = KeyControl();

        switch (key)
        {
        case UP:
            if (y > MAP_HEIGHT / 3)
            {
                Gotoxy(x - 2, y);
                std::cout << " ";
                Gotoxy(x - 2, --y);
                std::cout << ">";
            }
            break;
        case DOWN:
            if (y < MAP_HEIGHT / 3 + 4)
            {
                Gotoxy(x - 2, y);
                std::cout << " ";
                Gotoxy(x - 2, ++y);
                std::cout << ">";
            }
            break;
        case SPACE:
            system("cls");
            return y - MAP_HEIGHT / 3; // 선택된 메뉴 반환
        }
    }
}

void SubMenu::Menu(Player* p)
{
    system("cls");

    switch (SelectMenu())
    {
    case 0:
        // 포켓몬
        Gotoxy(0, y);
        std::cout << p->GetPName() << std::endl;
        Gotoxy(x, y + 1);
        std::cout << "HP: " << p->GetPHP() << ", Level: " << p->GetPLevel() << std::endl;
        Sleep(3000);
        break;
    case 1:
        // 가방
        Gotoxy(0, y);
        std::cout << "가방" << std::endl;
        p->ShowIven();
        Sleep(3000);
        break;
    case 2:
        // 레포트
        Gotoxy(x, y);
        std::cout << "저장 중입니다. 전원을 끄지 마세요." << std::endl;
        Sleep(3000);
        system("cls");
        Gotoxy(x, y);
        std::cout << "저장되었습니다." << std::endl;
        Sleep(2000);
        break;
    case 3:
        // 닫다
        break;
    case 4:
        // 끈다
        exit(0);
        break;
    }

    system("cls");
}

