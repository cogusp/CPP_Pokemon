#pragma once
#include "Player.h"
#include "Controller.h"
#include <iostream>

class TutorialPage
{
private:
	Player* mPlayer;
	Controller* mController;

public:
	TutorialPage();
	~TutorialPage();

	void InputPlayerInfo();
	void ShowGameInfo();
};