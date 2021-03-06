// https://www.acmicpc.net/problem/1010

#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int n, r;
	int caches[30][30];

	void Input()
	{
		std::cin >> r >> n;
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

		std::cout << GetCombi(n, r) << '\n';
	}

	int GetCombi(int n, int r)
	{
		if (n == r || r == 0)
		{
			return 1;
		}

		auto& cache = caches[n][r];
		if (cache != -1)
		{
			return cache;
		}

		return cache = GetCombi(n - 1, r) + GetCombi(n - 1, r - 1);
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