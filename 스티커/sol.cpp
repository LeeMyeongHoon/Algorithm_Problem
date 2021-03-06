#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int endJ;
	std::vector<int> data[2];
	std::vector<int> dp[2];


	void Input()
	{
		scanf("%d", &endJ);
		data[0].assign(endJ, {});
		data[1].assign(endJ, {});

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < endJ; j++)
			{
				scanf("%d", &data[i][j]);
			}
		}
	}

	int GetMax(int i, int j)
	{
		if (j >= endJ)
		{
			return 0;
		}

		auto& cache = dp[i][j];
		if (cache != -1)
		{
			return cache;
		}

		return cache = data[i][j] + std::max(GetMax(!i, j + 1), GetMax(!i, j + 2));
	}

	void Solve()
	{
		for (auto& cache : dp)
		{
			cache.assign(endJ, -1);
		}

		int max = std::max(GetMax(0, 0), GetMax(1, 0));

		std::cout << max << '\n';
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
