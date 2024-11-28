#include "Shop.h"

Shop::Shop()
{
    SetItems();
}

Shop::~Shop() {}

void Shop::SetItems()
{
    // json or csv file
    AddItem(Item("몬스터볼", "포켓몬 잡는 거", 100, 0, 0));
}

void Shop::ShowItems() const
{
    std::cout << "목록" << std::endl;

    for (int i = 0; i < items.size(); ++i)
    {
        std::cout << i + 1 << ". " << items[i].GetName() << "\t" << items[i].GetPrice() << std::endl;
    }
}

Item* Shop::BuyItem(const int index, int& coin)
{
    Item& item = items[index];

    if (coin < item.GetPrice())
        return nullptr;
    
    coin -= item.GetPrice();
    std::cout << "구매 성공" << std::endl;

    return &item;
}

void Shop::AddItem(const Item& item)
{
    items.push_back(item);
}
