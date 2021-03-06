// https://www.acmicpc.net/problem/2193

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int maxDigit;
	unsigned long long caches[91];

	void Input()
	{
		std::cin >> maxDigit;
	}

	void Solve()
	{
		if (maxDigit == 1)
		{
			std::cout << 1 << '\n';
		}

		else
		{
			for (int i = 0; i <= maxDigit; i++)
			{
				caches[i] = -1;
			}
			std::cout << GetCount(maxDigit - 2) << '\n';
		}
	}

	unsigned long long GetCount(int digit)
	{
		if (digit <= 0)
		{
			return 1;
		}

		auto& cache = caches[digit];
		if (cache != -1)
		{
			return cache;
		}

		return cache =  GetCount(digit - 2) + GetCount(digit - 1);
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}