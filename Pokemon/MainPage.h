#pragma once
#include "Map.h"
#include "Controller.h"

class MainPage : public Controller
{
private:
	Map* mMap;

public:
	MainPage();
	~MainPage();

	void GameLoop();
	void Move(int*, int*, int, int);
	void Draw(int*, int*);
};

