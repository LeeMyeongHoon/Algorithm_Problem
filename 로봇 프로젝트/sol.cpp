// https://www.acmicpc.net/problem/3649

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int target;
	int legoCount;

	std::vector<int> lengthes;

	bool Input()
	{
		if (std::cin >> target)
		{
			target *= 10000000;

			scanf("%d", &legoCount);
			lengthes.assign(legoCount, {});

			for (auto& length : lengthes)
			{
				scanf("%d", &length);
			}

			return true;
		}

		return false;
	}

	struct Data
	{
		int a, b;
	};

	void Solve()
	{
		if (legoCount < 2)
		{
			printf("danger\n");
			return;
		}

		std::sort(std::begin(lengthes), std::end(lengthes));
		Data result = { -1,-1 };

		for (auto length : lengthes)
		{
			int other = target - length;
			if (other <= 0)
			{
				continue;
			}

			if (other == length)
			{
				auto range = std::equal_range(std::begin(lengthes), std::end(lengthes), length);
				if (range.second - range.first > 1)
				{
					if (result.a == -1)
					{
						result.a = length;
						result.b = length;
					}
				}
			}

			else if (length > other)
			{
				break;
			}

			else
			{
				if (std::binary_search(std::begin(lengthes), std::end(lengthes), other))
				{
					if (std::abs(result.a - result.b) < std::abs(length - other))
					{
						result.a = length;
						result.b = other;
					}
				}
			}
		}

		if (result.a == -1)
		{
			printf("danger\n");
		}

		else
		{
			if (result.a > result.b)
			{
				std::swap(result.a, result.b);
			}

			printf("yes %d %d\n", result.a, result.b);
		}
	}
};

int main()
{
	while (true)
	{
		Soluter soluter;
		if (!soluter.Input())
		{
			break;
		}
		soluter.Solve();
	}
	return 0;
}