// https://www.acmicpc.net/problem/11722

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int count;
	std::vector<int> numbers;

	void Input()
	{
		int count;
		std::cin >> count;

		numbers.assign(count, {});
		for (auto& num : numbers)
		{
			std::cin >> num;
		}
	}

	void Solve()
	{
		std::vector<int> lds;
		for (int i = 1; i < numbers.size(); i++)
		{

		}
	}
};