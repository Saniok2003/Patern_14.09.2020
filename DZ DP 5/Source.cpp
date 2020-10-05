#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define cls system("cls");

class Game
{
private:
	const char player = '@';
	static const int x = 43, y = 25;
	char map[y][x];
	int y1 =1 , x1=1;
public:
	Game()
	{
		char symvol;
		ifstream in1("map.txt");
		for (int i = 0; i < this->y; i++)
		{
			for (int j = 0; j < this->x; j++)
			{
				in1.get(symvol);
				map[i][j] = symvol;
			}
		}
		in1.close();
	}
	void Show()
	{
		map[y1][x1] = player;
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x - 1; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}
	}
	int Play()
	{
		int act = 0;
		for (;;)
		{
			cls
				Show();
			cout << "1 - (+7)\t2 - (+4)\t3 - (+2)\n4 - (-1)\t5 - (-3)\t6 - (-6)\n";
			cout << "Enter action: ";
			cin >> act;
			if (act <= 6 && act >= 1)
			{
				switch (act)
				{
				case 1:
				{
					cls
						map[++y1][x1 = x1 + 7] = player;
				}break;
				case 2:
				{
					cls
					map[++y1][x1 = x1 + 4] = player;
				}break;
				case 3:
				{
					cls
					map[++y1][x1 = x1 + 2] = player;
				}break;
				case 4:
				{
					cls
					map[++y1][x1 = x1 - 1] = player;
				}break;
				case 5:
				{
					cls
					map[++y1][x1 = x1 - 3] = player;
				}break;
				case 6:
				{
					cls
					map[++y1][x1 = x1 - 6] = player;
				}break;
				default:
					cout << "\nError404\n" << endl;
					return 0;
					break;
				}
			}
		}
	}
};

int main()
{
	Game s;
	s.Play();
	system("pause");
	return 0;
}
