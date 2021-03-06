// https://www.acmicpc.net/problem/1475

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Soluter
{
	std::string str;

	void Input()
	{
		std::cin >> str;
	}

	void Solve()
	{
		int numCount[10] = { 0 };
		for (auto& numChar : str)
		{
			numCount[numChar - '0']++;
		}
		numCount[6] = 0;
		numCount[9] = 0;

		int sixNineCount = std::count_if(std::begin(str), std::end(str), [](char num) { return num == '6' || num == '9'; });
		int sixNineSetCount = (sixNineCount % 2 == 0 ? sixNineCount / 2 : sixNineCount / 2 + 1);

		int maxCount = *std::max_element(std::begin(numCount), std::end(numCount));
		maxCount = std::max(maxCount, sixNineSetCount);

		std::cout << maxCount << '\n';

	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}