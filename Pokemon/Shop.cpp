#include "Shop.h"

Shop::Shop()
{
    SetItems();
}

Shop::~Shop() {}

void Shop::SetItems()
{
    AddItem(Item("���ͺ�", "���ϸ��� ���� �� �ִ� ����", 10, 0, 0));
    AddItem(Item("��ó��", "��ģ ���ϸ��� ġ���� �� �ִ� ��", 10, 30, 0));
    AddItem(Item("��������", "�޴��� ����", 7, 10, 0));
}

int Shop::SelectMenu()
{
    int select;
    std::cout << "����(1), �Ǹ�(2), ������(3): ";
    std::cin >> select;

    if (select == 1 || select == 2 || select == 3)
    {
        return select;
    }

    std::cout << "�߸��� �Է��Դϴ�. �ٽ� �����ϼ���." << std::endl;
    SelectMenu();
}


void Shop::ShowItems() const
{
    std::cout << "���" << std::endl;

    for (int i = 0; i < items.size(); ++i)
    {
        std::cout << i + 1 << ". " << items[i].GetName() << "\t" << items[i].GetPrice() << std::endl;
    }
}

void Shop::BuyItem(Player* mPlayer)
{
    ShowItems();

    std::cout << "���� ��: " << mPlayer->GetCoin() << std::endl;
    std::cout << "������ ���� ����: ";
    int index;
    std::cin >> index;

    Item& item = items[index - 1];

    int coin = mPlayer->GetCoin();

    if (coin < item.GetPrice())
    {
        std::cout << "���� ����" << std::endl;
        return;
    }

    mPlayer->SetCoin(coin -= item.GetPrice());
    item.SetCount(item.GetCount() + 1);
    mPlayer->AddItemToInven(item);
    std::cout << "���� ����" << std::endl;
}

void Shop::AddItem(const Item& item)
{
    items.push_back(item);
}
