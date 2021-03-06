#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int n, k;
	int caches[11][11];

	void Input()
	{
		std::cin >> n >> k;
	}


	int GetAns(int n, int k)
	{
		if (k == n)
		{
			return 1;
		}

		if (k == 0)
		{
			return 1;
		}

		auto& cache = caches[n][k];
		if (cache != -1)
		{
			return cache;
		}

		return cache = GetAns(n - 1, k) + GetAns(n - 1, k - 1);
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
		std::cout << GetAns(n, k) << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();
	return 0;
}