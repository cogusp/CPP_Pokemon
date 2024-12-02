#pragma once
#include "Render.h"
#include "Controller.h"

class MainPage : public Controller
{
private:
	Render* mRender;
	

public:
	MainPage();
	~MainPage();

	int isPlay = 0;

	int GameLoop();
};

