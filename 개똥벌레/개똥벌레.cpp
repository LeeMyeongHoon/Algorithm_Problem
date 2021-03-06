// https://www.acmicpc.net/problem/3020

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int obstacle;

	int height;

	std::vector<int> bottom;
	std::vector<int> top;

	void Input()
	{
		std::cin >> obstacle >> height;

		top.assign(obstacle / 2, {});
		bottom.assign(obstacle / 2, {});

		for (int i = 0; i < obstacle / 2; i++)
		{
			std::cin >> bottom[i] >> top[i];
		}
	}

	struct Data
	{
		int height;
		int breakCount;
	};

	void Solve()
	{
		std::sort(std::begin(bottom), std::end(bottom));
		std::sort(std::begin(top), std::end(top));

		int min = std::numeric_limits<int>::max();
		int count = 0;

		for (int downFly = 1; downFly <= height; downFly++)
		{
			int breakCount = 0;
			breakCount += (std::end(bottom) - std::lower_bound(std::begin(bottom), std::end(bottom), downFly));

			int upFly = height - downFly + 1;
			breakCount += (std::end(top) - std::lower_bound(std::begin(top), std::end(top), upFly));

			if (breakCount < min)
			{
				min = breakCount;
				count = 1;
			}
			else if (breakCount == min)
			{
				count++;
			}
		}

		std::cout << min << ' ' << count << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}