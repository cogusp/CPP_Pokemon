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
	std::cout << std::endl << "���� �̸���?\t";

	std::string name;
	std::cin >> name;

	mPlayer->SetName(name);
}

void TutorialPage::ShowGameInfo()
{
	std::cout << "�� ���ڻ��� �ϳ�." << std::endl;
	Sleep(1000);
	std::cout << "�켱 �ڳ��� �̸��� �˷��ְԳ�!" << std::endl;
	Sleep(1000);

	InputPlayerInfo();

	std::cout << std::endl << mPlayer->GetName() << "... ���� �̸��̱�!" << std::endl;
	
	Sleep(1000);
	std::cout << "���ϸ����� �����!" << std::endl;
	std::cout << "���� ��-!" << std::endl;

	Sleep(2000);
}