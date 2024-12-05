#include "Shop.h"

Shop::Shop()
{
    SetItems();
}

Shop::~Shop() {}

void Shop::SetItems()
{
    AddItem(Item("몬스터볼", "포켓몬을 잡을 수 있는 도구", 10, 0, 0));
    AddItem(Item("상처약", "다친 포켓몬을 치료할 수 있는 약", 10, 30, 0));
    AddItem(Item("오랭열매", "달달한 열매", 7, 10, 0));
}

int Shop::SelectMenu()
{
    int select;
    std::cout << "구매(1), 판매(2), 나가기(3): ";
    std::cin >> select;

    if (select == 1 || select == 2 || select == 3)
    {
        return select;
    }

    std::cout << "잘못된 입력입니다. 다시 선택하세요." << std::endl;
    SelectMenu();
}


void Shop::ShowItems() const
{
    std::cout << "목록" << std::endl;

    for (int i = 0; i < items.size(); ++i)
    {
        std::cout << i + 1 << ". " << items[i].GetName() << "\t" << items[i].GetPrice() << std::endl;
    }
}

void Shop::BuyItem(Player* mPlayer)
{
    ShowItems();

    std::cout << "가진 돈: " << mPlayer->GetCoin() << std::endl;
    std::cout << "구매할 물건 선택: ";
    int index;
    std::cin >> index;

    Item& item = items[index - 1];

    int coin = mPlayer->GetCoin();

    if (coin < item.GetPrice())
    {
        std::cout << "현금 부족" << std::endl;
        return;
    }

    mPlayer->SetCoin(coin -= item.GetPrice());
    item.SetCount(item.GetCount() + 1);
    mPlayer->AddItemToInven(item);
    std::cout << "구매 성공" << std::endl;
}

void Shop::AddItem(const Item& item)
{
    items.push_back(item);
}
