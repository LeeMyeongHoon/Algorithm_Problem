#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int endI, endJ;
	bool isLand[50][50];

	bool Input()
	{
		std::cin >> endJ >> endI;
		if (endI == 0 && endJ == 0)
		{
			return false;
		}

		for (int i = 0; i < endI; i++)
		{
			for (int j = 0; j < endJ; j++)
			{
				std::cin >> isLand[i][j];
			}
		}

		return true;
	}

	void FloodFill(int i, int j)
	{
		if (i >= endI || j >= endJ || j < 0 || i < 0)
		{
			return;
		}

		if (!isLand[i][j])
		{
			return;
		}

		isLand[i][j] = false;

		FloodFill(i + 1, j);
		FloodFill(i - 1, j);
		FloodFill(i, j + 1);
		FloodFill(i, j - 1);
		FloodFill(i + 1, j + 1);
		FloodFill(i + 1, j - 1);
		FloodFill(i - 1, j + 1);
		FloodFill(i - 1, j - 1);
	}

	void Solve()
	{
		int count = 0;
		for (int i = 0; i < endI; i++)
		{
			for (int j = 0; j < endJ; j++)
			{
				if (isLand[i][j])
				{
					count++;
					FloodFill(i, j);
				}
			}
		}

		std::cout << count << '\n';
	}
};


int main()
{
	while (true)
	{
		Soluter soluter;
		if (!soluter.Input())
		{
			break;
		}
		soluter.Solve();
	}

	return 0;
}