#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int n;
	int caches[1001];

	void Input()
	{
		std::cin >> n;
	}

	int GetCount(int n)
	{
		if (n < 0)
		{
			return 0;
		}
		if (n == 0)
		{
			return 1;
		}

		auto& cache = caches[n];
		if (cache != -1)
		{
			return cache;
		}

		return cache = (2 * GetCount(n - 2) + GetCount(n - 1)) % 10007;
	}

	void Solve()
	{
		for (int i = 0; i <= n; i++)
		{
			caches[i] = -1;
		}

		std::cout << GetCount(n) << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}