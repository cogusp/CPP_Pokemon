#include "SubMenu.h"

void SubMenu::MenuList()
{
	Gotoxy(x - 2, y);
	std::cout << "> ���ư���" << std::endl;
	Gotoxy(x, y + 1);
	std::cout << "�κ��丮" << std::endl;
	Gotoxy(x, y + 2);
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
            if (y > 12)
            {
                Gotoxy(x - 2, y);
                std::cout << " ";
                Gotoxy(x - 2, --y);
                std::cout << ">";
            }
            break;
        case DOWN:
            if (y < 14)
            {
                Gotoxy(x - 2, y);
                std::cout << " ";
                Gotoxy(x - 2, ++y);
                std::cout << ">";
            }
            break;
        case SPACE:
            system("cls");
            return y - 12; // ���õ� �޴� ��ȯ
        }
    }
}

