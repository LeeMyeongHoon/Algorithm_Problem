// https://www.acmicpc.net/problem/1094

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

struct Soluter
{
	unsigned int x;

	void Input()
	{
		std::cin >> x;
	}

	void Solve()
	{
		int count = 0;
		for (int i = 0; i < 7; i++)
		{
			if (x & 1)
			{
				count++;
			}
			x = x >> 1;
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