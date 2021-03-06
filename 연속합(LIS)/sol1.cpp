#ifdef 시간초과_단순부분합

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int size;
	std::vector<int> sums;

	void Input()
	{
		std::cin >> size;
		sums.assign(size, {});

		int num;
		std::cin >> num;
		sums[0];
		for (int i = 1; i < size; i++)
		{
			std::cin >> num;
			sums[i] = sums[i - 1] + num;
		}
	}

	void Solve()
	{
		int max = std::numeric_limits<int>::min();
		for (int back = 0; back < size; back++)
		{
			for (int front = 1; front <= back; front++)
			{
				max = std::max(max, sums[back] - sums[front - 1]);
			}
		}

		for (int back = 0; back < size; back++)
		{
			max = std::max(max, sums[back]);
		}

		std::cout << max << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();
	return 0;
}
#endif // SOL_1
