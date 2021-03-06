#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int totalN;
	std::vector<int> costs;
	int caches[1001];

	void Input()
	{
		std::cin >> totalN;
		costs.assign(totalN + 1, {});
		for (int i = 1; i <= totalN; i++)
		{
			std::cin >> costs[i];
		}
	}

	void Solve()
	{
		for (int i = 0; i <= totalN; i++)
		{
			caches[i] = -1;
		}
		std::cout << GetMax(totalN) << '\n';
	}

	int GetMax(int n)
	{
		if (n == 0)
		{
			return 0;
		}

		auto& cache = caches[n];
		if (cache != -1)
		{
			return cache;
		}

		int max = std::numeric_limits<int>::min();
		for (int i = 1; i <= totalN; i++)
		{
			if (n - i >= 0)
			{
				max = std::max(max, costs[i] + GetMax(n - i));
			}
		}

		return cache = max;
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}