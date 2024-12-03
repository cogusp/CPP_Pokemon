#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {}

Inventory::~Inventory() {}

void Inventory::ShowInven() const
{
    if (items.empty())
        std::cout << "�κ��丮�� �����." << std::endl;
    else
    {
        std::cout << "===== �κ��丮 =====" << std::endl;

        for (int i = 0; i < items.size(); ++i)
        {
            std::cout << i + 1 << ". " << items[i].GetName() << "\t" << items[i].GetCount() << std::endl;
        }

        std::cout << "=====================" << std::endl;
    }
}

void Inventory::AddItem(const Item& item)
{
    for (auto it : items)
    {
        if (it.GetName().compare(item.GetName()) == 0)
        {
            it.SetCount(it.GetCount() + 1);
            return;
        }
    }

    items.push_back(item);
    items[0].SetCount(1);
}

int Inventory::SellItem(int& coin)
{
    if (items.empty())
    {
        std::cout << "�κ��丮�� ������ϴ�." << std::endl;
        return 0;
    }

    ShowInven();

    std::cout << "�� ���� ��ȣ ����: ";
    int index;
    std::cin >> index;

    if (items[index - 1].GetCount() - 1 == 0)
        items.erase(items.begin() + (index - 1));
    else
        items[index - 1].SetCount(items[index - 1].GetCount() - 1);

    std::cout << "���������� �Ǹ��߽��ϴ�!" << std::endl;

    return coin += items[index - 1].GetPrice();
}

void Inventory::UseItem()
{
    ShowInven();

    std::cout << "�� ���� ��ȣ ����: ";
    int index;
    std::cin >> index;

    std::cout << items[index - 1].GetName() << "��(��) ����߽��ϴ�!" << std::endl;

    if (items[index - 1].GetCount() - 1 == 0)
        items.erase(items.begin() + (index - 1));
    else
        items[index - 1].SetCount(items[index - 1].GetCount() - 1);

    // heal up
}
