// https://www.acmicpc.net/problem/1929

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
		for (int i = start; i <= last; i++)
		{
			if (IsPrime(i))
			{
				std::cout << i << '\n';
			}
		}
	}

	bool IsPrime(int n)
	{
		if (n == 1)
		{
			return false;
		}
		if (n == 2)
		{
			return true;
		}

		for (int divider = 2; divider <= std::sqrt(n); divider++)
		{
			if (n % divider == 0)
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