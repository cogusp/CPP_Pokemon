#include "NPC.h"

NPC::NPC()
{
	nRender = new Render();
	nPokemon = new Pokemon();
}

NPC::~NPC()
{
	delete nPokemon;
	delete nRender;
	nPokemon = nullptr;
	nRender = nullptr;
}

void NPC::Script(Player* p) const
{
	nRender->Init();
	nRender->Gotoxy(0, 0);

	std::cout << "바람이가 결투를 신청했다." << std::endl;

	std::cout << "바람이는 " << nPokemon->GetName() << "을/를 내보냈다." << std::endl;

	while (true)
	{
		State(p);

		std::cout << std::endl << "== Fight ==" << std::endl;

		std::cout << "무엇을 할까?" << std::endl;
		std::cout << "1. 싸운다 2. 도망간다" << std::endl;

		int select;
		std::cin >> select;

		if (select == 2)
		{
			std::cout << std::endl << "도망칠 수 없다!!" << std::endl << std::endl;
			continue;
		}

		std::cout << "1. " << p->GetPSkill1() << ", 공격력: " << p->GetPAtk1() << std::endl;
		std::cout << "2. " << p->GetPSkill2() << ", 공격력: " << p->GetPAtk2() << std::endl;

		std::cout << "공격 선택: ";
		std::cin >> select;
		std::cout << std::endl;

		switch (select)
		{
		case 1:
			nPokemon->SetHP(nPokemon->GetHP() - p->GetPAtk1());
			break;
		case 2:
			nPokemon->SetHP(nPokemon->GetHP() - p->GetPAtk2());
			break;
		default:
			break;
		}

		State(p);

		if (p->GetPHP() <= 0 || nPokemon->GetHP() <= 0)
			break;

		switch (rand() % 2 + 1)
		{
		case 1:
			p->SetHP(p->GetPHP() - nPokemon->GetAtk1());
			break;
		case 2:
			p->SetHP(p->GetPHP() - nPokemon->GetAtk2());
			break;
		}

		State(p);

		if (p->GetPHP() <= 0 || nPokemon->GetHP() <= 0)
			break;
	}

	if (p->GetPHP() > nPokemon->GetHP())
	{
		std::cout << "바람과의 승부에서 이겼습니다!!" << std::endl;
		Sleep(3000);
	}
	else
	{
		std::cout << "바람과의 승부에서 패배했습니다.." << std::endl;
		Sleep(3000);
	}
}

void NPC::State(Player* p) const
{
	std::cout << "== State ==" << std::endl;

	std::cout << "바람의 " << nPokemon->GetName() << std::endl;
	std::cout << "HP: " << nPokemon->GetHP() << ", Level: " << nPokemon->GetLevel() << std::endl;

	std::cout << std::endl;

	std::cout << p->GetName() << "의 " << p->GetPName() << std::endl;
	std::cout << "HP: " << p->GetPHP() << ", Level: " << p->GetPLevel() << std::endl;

	std::cout << std::endl;
}

std::string NPC::GetPName()
{
	return nPokemon->GetName();
}

int NPC::GetPHP()
{
	return nPokemon->GetHP();
}

int NPC::GetPLevel()
{
	return nPokemon->GetLevel();
}

Pokemon* NPC::GetPokemon()
{
	return nPokemon;
}

void NPC::SetPokemon(Pokemon& p)
{
	std::cout << p.GetName() << std::endl;
	nPokemon->SetName(p.GetName());

	nPokemon->SetHP(p.GetHP());
	nPokemon->SetLevel(p.GetLevel());
	nPokemon->SetSkill(p.GetSkill1(), p.GetSkill2());
	nPokemon->SetAtk(p.GetAtk1(), p.GetAtk2());
}
