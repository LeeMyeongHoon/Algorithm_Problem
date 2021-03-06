#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

struct Soluter
{
	std::vector<std::vector<int>> data;
	std::vector<std::vector<int>> caches;
	int endI, endJ;

	void Input()
	{
		std::cin >> endI >> endJ;
		data.assign(endI, std::vector<int>(endJ, {}));
		caches = data;

		for (int i = 0; i < endI; i++)
		{
			for (int j = 0; j < endJ; j++)
			{
				std::cin >> data[i][j];
			}
		}
	}

	int GetMax(int i, int j)
	{
		if (i >= endI || j >= endJ)
		{
			return std::numeric_limits<int>::min();
		}
		if (i == endI - 1 && j == endJ - 1)
		{
			return data[i][j];
		}

		auto& cache = caches[i][j];
		if (cache != -1)
		{
			return cache;
		}

		int max = data[i][j] + std::max({ GetMax(i + 1, j), GetMax(i, j + 1), GetMax(i + 1, j + 1) });

		return cache = max;
	}

	void Solve()
	{
		for (auto& caches1 : caches)
		{
			for (auto& caches2 : caches1)
			{
				caches2 = -1;
			}
		}
		std::cout << GetMax(0, 0) << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}