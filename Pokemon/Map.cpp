#include "Map.h"

void Map::DrawMap(int* x, int* y)
{
	char map[11][13] = {
		{"11110dd01111"},
		{"111102201111"},
		{"111102201111"},
		{"111102201111"},
		{"000002200000"},
		{"222222222222"},
		{"222222222222"},
		{"2bbb2222bbb2"},
		{"2bbb2222bbb2"},
		{"22p222222222"},
		{"222222222222"}
	};

	system("cls");

	for (int h = 0; h < 11; ++h)
	{
		for (int w = 0; w < 13; ++w)
		{
			char temp = map[h][w];

			if (temp == '0')
				std::cout << "●";
			else if (temp == '1')
				std::cout << "▦";
			else if (temp == '2')
				std::cout << "  ";
			else if (temp == 'b')
				std::cout << "■";
			else if (temp == 'd')
				std::cout << "△";
			else if (temp == 'p')
			{
				*x = w;
				*y = h;
				std::cout << 'P';
			}
		}
		std::cout << std::endl;
	}
	Sleep(3000);
}
