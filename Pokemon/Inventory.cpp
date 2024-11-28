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
    items.push_back(item);
}

Item Inventory::SellItem(const int index, int& coin)
{
    if (items.empty())
    {
        std::cout << "없음" << std::endl;
        return Item();
    }

    Item& soldItem = items[index - 1];

    int price = soldItem.GetPrice();
    coin += price;

    items.erase(items.begin() + (index + 1));

    std::cout << "성공적으로 판매했습니다!" << std::endl;

    return soldItem;
}

void Inventory::UseItem(const int index)
{
    std::cout << items[index - 1].GetName() << "을(를) 사용했습니다!" << std::endl;
    items.erase(items.begin() + (index - 1));

    // heal up
}
