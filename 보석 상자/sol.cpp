// https://www.acmicpc.net/problem/2792

#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int children;
	int colorCount;
	int max = -1;

	std::vector<int> counts;

	void Input()
	{
		std::cin >> children >> colorCount;

		counts.assign(colorCount, {});

		for (auto& count : counts)
		{
			std::cin >> count;
			if (max < count)
			{
				max = count;
			}
		}
	}

	void Solve()
	{
		int down = 1;
		int up = max;
		int result;
		while (down <= up)
		{
			int mid = (down + up) / 2;
			int sum = 0;
			for (auto& count : counts)
			{
				if (count % mid == 0)
				{
					sum += (count / mid);
				}
				else
				{
					sum += (count / mid + 1);
				}
			}

			if (sum > children)
			{
				down = mid + 1;
			}
			else
			{
				result = mid;
				up = mid - 1;
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