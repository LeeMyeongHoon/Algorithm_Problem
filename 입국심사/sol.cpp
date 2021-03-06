// https://www.acmicpc.net/problem/3079


#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	size_t people;
	size_t judge;

	std::vector<size_t> judgeTimes;
	size_t maxTime = 0;

	void Input()
	{
		std::cin >> judge >> people;

		judgeTimes.assign(judge, {});
		for (auto& time : judgeTimes)
		{
			std::cin >> time;
			if (maxTime < time)
			{
				maxTime = time;
			}
		}
	}

	void Solve()
	{
		size_t up = maxTime * people;
		size_t down = 1;
		size_t totalTime;
		size_t result;
		while (down <= up)
		{
			totalTime = (down + up) / 2;
			size_t sum = 0;
			for (auto& judgeTime : judgeTimes)
			{
				sum += (totalTime / judgeTime);
			}

			if (sum >= people)
			{
				result = totalTime;
				up = totalTime - 1;
			}
			else
			{
				down = totalTime + 1;
			}
		}

		std::cout << result << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}