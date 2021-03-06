// https://www.acmicpc.net/problem/10942

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int numCount;
	std::vector<int> numbers;

	int rangeCount;
	std::vector<std::pair<int, int>> ranges;

	void Input()
	{
		std::cin >> numCount;
		numbers.assign(numCount + 1, {});
		for (int i = 1; i <= numCount; i++)
		{
			std::cin >> numbers[i];
		}

		std::cin >> rangeCount;
		ranges.assign(rangeCount, {});
		for (auto& range : ranges)
		{
			std::cin >> range.first >> range.second;
		}
	}

	void Solve()
	{
		for (auto& range : ranges)
		{
			int front = range.first;
			int back = range.second;
			int count = (back - front + 1) / 2;

			bool isOk = true;
			for (int i = 0; i < count; i++)
			{
				if (numbers[front] != numbers[back])
				{
					isOk = false;
					break;
				}
				front++;
				back--;
			}

			std::cout << isOk << '\n';
		}
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}