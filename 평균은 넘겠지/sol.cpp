// https://www.acmicpc.net/problem/4344

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Soluter
{
	int count;
	int sum;
	std::vector<int> scores;

	void Input()
	{
		std::cin >> count;
		scores.assign(count, {});
		sum = 0;
		for (auto& score : scores)
		{
			std::cin >> score;
			sum += score;
		}
	}

	void Solve()
	{
		int pass = 0;
		double aver = (double)sum / count;
		for (auto& score : scores)
		{
			if (score > aver)
			{
				pass++;
			}
		}

		std::cout << std::fixed << std::setprecision(3) << (double)pass / count * 100 << "%\n";
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