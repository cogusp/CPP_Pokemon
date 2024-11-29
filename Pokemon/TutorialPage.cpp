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
	std::cout << "���� �̸���?" << std::endl;

	std::string name;
	std::cin >> name;

	mPlayer->SetName(name);
}

void TutorialPage::ShowGameInfo()
{
	std::cout << "����? �� ���ڻ�." << std::endl;

	InputPlayerInfo();

	std::cout << mPlayer->GetName() << "... ���� �̸��̱�!" << std::endl;
	std::cout << "����� ���!" << std::endl;

	Sleep(3000);
}