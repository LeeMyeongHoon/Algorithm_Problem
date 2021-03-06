// https://www.acmicpc.net/problem/2581

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>

struct Soluter
{
	int start;
	int last;

	void Input()
	{
		std::cin >> start >> last;
	}

	void Solve()
	{
		std::vector<int> primeNums;
		for (int i = start; i <= last; i++)
		{
			if (IsPrimeNum(i))
			{
				primeNums.push_back(i);
			}
		}

		if (primeNums.empty())
		{
			std::cout << -1 << '\n';
		}
		else
		{
			std::cout << std::accumulate(std::begin(primeNums), std::end(primeNums), 0) << '\n';
			std::cout << primeNums.front() << '\n';
		}
	}

	bool IsPrimeNum(int n)
	{
		if (n == 1)
		{
			return false;
		}
		if (n == 2)
		{
			return true;
		}

		for (int i = 2; i <= std::sqrt(n); i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}