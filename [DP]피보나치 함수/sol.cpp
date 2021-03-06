// 

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	long long int num;
	long long int historyForZero[41];
	long long int historyForOne[41];


	void Input()
	{
		std::cin >> num;
	}

	void Solve()
	{
		for (auto& history : historyForZero)
		{
			history = -1;
		}

		for (auto& history : historyForOne)
		{
			history = -1;
		}

		std::cout << CountZero(num) << ' ' << CountOne(num) << " \n";
	}

	long long int CountZero(long long int n)
	{
		if (n == 0)
		{
			return 1;
		}
		if (n == 1)
		{
			return 0;
		}

		auto& cache = historyForZero[n];

		if (cache != -1)
		{
			return cache;
		}


		return cache = CountZero(n - 1) + CountZero(n - 2);
	}

	long long int CountOne(long long int n)
	{
		auto& cache = historyForOne[n];

		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return 1;
		}
		if (cache != -1)
		{
			return cache;
		}


		return cache = CountOne(n - 1) + CountOne(n - 2);
	}
};

int main()
{
	long long int count;
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