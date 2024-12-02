#include "GameManager.h"
#include "Render.h"

int main()
{
	Render render;
	render.Init();

	GameManager gameManager;
	gameManager.StartGame();
}