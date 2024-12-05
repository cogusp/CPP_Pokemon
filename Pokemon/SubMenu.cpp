#include "SubMenu.h"

void SubMenu::MenuList()
{
	Gotoxy(x - 2, y);
	std::cout << "> ���ϸ�" << std::endl;
	Gotoxy(x, y + 1);
	std::cout << "����" << std::endl;
	Gotoxy(x, y + 2);
	std::cout << "����Ʈ" << std::endl;
    Gotoxy(x, y + 3);
    std::cout << "�ݴ�" << std::endl;
    Gotoxy(x, y + 4);
    std::cout << "����" << std::endl;
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
            return y - MAP_HEIGHT / 3; // ���õ� �޴� ��ȯ
        }
    }
}

void SubMenu::Menu(Player* p)
{
    system("cls");

    switch (SelectMenu())
    {
    case 0:
        // ���ϸ�
        Gotoxy(0, y);
        std::cout << p->GetPName() << std::endl;
        Gotoxy(x, y + 1);
        std::cout << "HP: " << p->GetPHP() << ", Level: " << p->GetPLevel() << std::endl;
        Sleep(3000);
        break;
    case 1:
        // ����
        Gotoxy(0, y);
        std::cout << "����" << std::endl;
        p->ShowIven();
        Sleep(3000);
        break;
    case 2:
        // ����Ʈ
        Gotoxy(x, y);
        std::cout << "���� ���Դϴ�. ������ ���� ������." << std::endl;
        Sleep(3000);
        system("cls");
        Gotoxy(x, y);
        std::cout << "����Ǿ����ϴ�." << std::endl;
        Sleep(2000);
        break;
    case 3:
        // �ݴ�
        break;
    case 4:
        // ����
        exit(0);
        break;
    }

    system("cls");
}

