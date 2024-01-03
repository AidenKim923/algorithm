#include <iostream>

using namespace std;

int confetti[130][130];
int blue, white;

void fold(int x, int y, int size)
{
	int check = confetti[x][y];

	for (int i = x; x + size > i; ++i)
	{
		for (int j = y; y + size > j; ++j)
		{
			if (confetti[i][j] != check)
			{
				check = 2;
			}
			if (check == 2)
			{
				fold(x, y, size / 2);
				fold(x, y + size / 2, size / 2);
				fold(x + size / 2, y, size / 2);
				fold(x + size / 2, y + size / 2, size / 2);
				
				return;
			}
		}
	}
	if (check == 0)
	{
		white++;
	}
	else
	{
		blue++;
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	
	cin >> n;
	for (int i = 0; n > i; ++i)
	{
		for (int j = 0; n > j; ++j)
		{
			cin >> confetti[i][j];
		}
	}
	fold(0, 0, n);
	cout << white << endl;
	cout << blue << endl;

	return 0;

}
