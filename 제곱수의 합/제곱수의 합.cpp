// https://www.acmicpc.net/problem/1699

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Soluter
{
	int n;
	std::vector<int> caches;

	void Input()
	{
		std::cin >> n;
	}

	int GetMin(int n)
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

		int min = std::numeric_limits<int>::max();
		for (int i = 1; i <= sqrt(n); i++)
		{
			int nextN = n - i * i;
			if (nextN >= 0)
			{
				min = std::min(min, 1 + GetMin(nextN));
			}
		}

		return cache = min;
	}

	void Solve()
	{
		caches.assign(n + 1, -1);
		caches[1] = 1;
		std::cout << GetMin(n) << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}