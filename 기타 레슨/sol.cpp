// https://www.acmicpc.net/problem/2343

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

struct Soluter
{
	int lesson;
	int blulayCount;

	std::vector<int> times;

	void Input()
	{
		std::cin >> lesson >> blulayCount;

		times.assign(lesson, {});

		for (auto& time : times)
		{
			std::cin >> time;
		}
	}

	void Solve()
	{
		int down = *std::max_element(std::begin(times), std::end(times));
		int up = std::accumulate(std::begin(times), std::end(times), 0);

		while (down <= up)
		{
			int maxSize = (up + down) / 2;
			int size = 0;
			int count = 1;

			for (int i = 0; i < lesson; i++)
			{
				if (size + times[i] <= maxSize)
				{
					size += times[i];
				}
				else
				{
					count++;
					size = times[i];
				}
			}

			if (count > blulayCount)
			{
				down = maxSize + 1;
			}

			else
			{
				up = maxSize - 1;
			}
		}

		std::cout << down << '\n';
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}