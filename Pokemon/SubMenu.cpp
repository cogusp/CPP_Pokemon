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
		int key = KeyControl();			// Ű���� �̺�Ʈ �Է� ��

		switch (key)
		{
		case UP:
			if (y > 12)					// y�� �̵� ����
			{
				Gotoxy(x - 2, y);		// �� ĭ ������ > ���
				std::cout << " ";		// ���� ��ġ ����
				Gotoxy(x - 2, --y);		// ��ġ �̵�
				std::cout << ">";		// �ٽ� �׸�
			}
			break;
		case DOWN:
			if (y < 14)					// y�� �̵� ����
			{
				Gotoxy(x - 2, y);		// �� ĭ ������ > ���
				std::cout << " ";		// ���� ��ġ ����
				Gotoxy(x - 2, ++y);		// ��ġ �̵�
				std::cout << ">";		// �ٽ� �׸�
			}
			break;
		case SPACE:
			system("cls");		// �ܼ�â�� ��� ���� ���� ��ǥ 0, 0 �ʱ�ȭ
			return y - 12;
		}
	}
}
