// https://www.acmicpc.net/problem/11057

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Soluter
{
	int n;
	std::vector<std::vector<int>> caches;

	void Input()
	{
		std::cin >> n;
	}

	int GetCount(int prevNum, int size)
	{
		if (size == 0)
		{
			return 1;
		}

		auto& cache = caches[prevNum][size];
		if (cache != -1)
		{
			return cache;
		}

		int count = 0;
		for (int newNum = prevNum; newNum <= 9; newNum++)
		{
			count += GetCount(newNum, size - 1);
			count %= 10007;
		}

		return cache = count;
	}

	void Solve()
	{
		caches.assign(10, std::vector<int>(1001, -1));

		int count = 0;
		for (int i = 0; i <= 9; i++)
		{
			count += GetCount(i, n - 1);
			count %= 10007;
		}
		std::cout << count << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}