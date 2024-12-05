#include "TutorialPage.h"

TutorialPage::TutorialPage()
{
	mController = new Controller();
}

TutorialPage::~TutorialPage()
{
	delete mController;
	mController = nullptr;
}

void TutorialPage::SetPlayer(Player* p)
{
	mPlayer = p;
}

void TutorialPage::InputPlayerInfo()
{
	std::cout << std::endl << "너의 이름은?\t";

	std::string name;
	std::cin >> name;

	mPlayer->SetName(name);
}

void TutorialPage::ShowGameInfo()
{
	std::cout << "난 오박사라고 하네." << std::endl;
	Sleep(1000);
	std::cout << "우선 자네의 이름을 알려주게나!" << std::endl;
	Sleep(1000);

	InputPlayerInfo();

	std::cout << std::endl << mPlayer->GetName() << "... 좋은 이름이군!" << std::endl;
	
	Sleep(1000);
	std::cout << "포켓몬스터의 세계로!" << std::endl;
	std::cout << "레츠 고-!" << std::endl;

	Sleep(2000);
}