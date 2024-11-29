#include "TutorialPage.h"

TutorialPage::TutorialPage()
{
	mPlayer = new Player();
	mController = new Controller();
}

TutorialPage::~TutorialPage()
{
	delete mPlayer;
	delete mController;
	mPlayer = nullptr;
	mController = nullptr;
}

void TutorialPage::InputPlayerInfo()
{
	std::cout << "너의 이름은?" << std::endl;

	std::string name;
	std::cin >> name;

	mPlayer->SetName(name);
}

void TutorialPage::ShowGameInfo()
{
	std::cout << "하이? 난 오박사." << std::endl;

	InputPlayerInfo();

	std::cout << mPlayer->GetName() << "... 좋은 이름이군!" << std::endl;
	std::cout << "행운을 비네!" << std::endl;

	Sleep(3000);
}