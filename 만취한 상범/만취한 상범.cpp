// https://www.acmicpc.net/problem/6359

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

struct Soluter
{
	int n;

	void Input()
	{
		std::cin >> n;
	}

	void Solve()
	{
		std::vector<bool> isOpenend(n + 1, false);
		for (int multi = 1; multi <= n; multi++)
		{
			int last = n / multi;
			for (int i = multi; i <= n; i += multi)
			{
				isOpenend[i].flip();
			}
		}

		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			if (isOpenend[i])
			{
				count++;
			}
		}
		std::cout << count << '\n';
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