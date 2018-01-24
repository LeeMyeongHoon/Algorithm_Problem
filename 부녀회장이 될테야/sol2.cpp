#ifdef Àç±ÍÀû µ¿Àû°èÈ¹
#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int k, n;
	int caches[15][15];

	void Input()
	{
		std::cin >> k >> n;
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
		std::cout << GetAnswer(k, n) << '\n';
	}

	int GetAnswer(int k, int n)
	{
		if (k == 0)
		{
			return n;
		}

		auto& cache = caches[k][n];

		if (cache != -1)
		{
			return cache;
		}

		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += GetAnswer(k - 1, i);
		}
		return cache = sum;
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
#endif // Àç±ÍÀû µ¿Àû°èÈ¹
