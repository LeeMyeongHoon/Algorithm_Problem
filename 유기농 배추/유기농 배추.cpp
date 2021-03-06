// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int width;
	int height;

	int count;

	int result = 0;
	bool HasCabbage[50][50] = { false };

	void Input()
	{
		std::cin >> width >> height >> count;
		for (int i = 0; i < count; i++)
		{
			int x;
			int y;
			std::cin >> x >> y;
			HasCabbage[y][x] = true;
		}
	}

	void Explore(int i, int j)
	{
		if (!HasCabbage[i][j])
		{
			return;
		}

		HasCabbage[i][j] = false;
		if (i + 1 < height)
		{
			Explore(i + 1, j);
		}
		if (i - 1 >= 0)
		{
			Explore(i - 1, j);
		}
		if (j + 1 < width)
		{
			Explore(i, j + 1);
		}
		if (j - 1 >= 0)
		{
			Explore(i, j - 1);
		}
	}

	void Solve()
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (HasCabbage[i][j])
				{
					result++;
					Explore(i, j);
				}
			}
		}

		std::cout << result << '\n';
	}
};

int main()
{
	int count;
	std::cin >> count;

	std::vector<Soluter> soluters(count);

	for (auto& soluter : soluters)
	{
		soluter.Input();
	}

	for (auto& soluter : soluters)
	{
		soluter.Solve();
	}

	return 0;
}