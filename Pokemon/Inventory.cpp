#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {}

Inventory::~Inventory() {}

void Inventory::ShowInven() const
{
    if (items.empty())
        std::cout << "인벤토리가 비었다." << std::endl;
    else
    {
        std::cout << "===== 인벤토리 =====" << std::endl;

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
        std::cout << "인벤토리가 비었습니다." << std::endl;
        return 0;
    }

    ShowInven();

    std::cout << "팔 물건 번호 선택: ";
    int index;
    std::cin >> index;

    if (items[index - 1].GetCount() - 1 == 0)
        items.erase(items.begin() + (index - 1));
    else
        items[index - 1].SetCount(items[index - 1].GetCount() - 1);

    std::cout << "성공적으로 판매했습니다!" << std::endl;

    return coin += items[index - 1].GetPrice();
}

void Inventory::UseItem()
{
    ShowInven();

    std::cout << "쓸 물건 번호 선택: ";
    int index;
    std::cin >> index;

    std::cout << items[index - 1].GetName() << "을(를) 사용했습니다!" << std::endl;

    if (items[index - 1].GetCount() - 1 == 0)
        items.erase(items.begin() + (index - 1));
    else
        items[index - 1].SetCount(items[index - 1].GetCount() - 1);

    // heal up
}
