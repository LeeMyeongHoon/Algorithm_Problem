// https://www.acmicpc.net/problem/14888

#include <iostream> 
#include <vector>
#include <algorithm>

const int PLUS = 0;
const int MINUS = 1;
const int MULITPLY = 2;
const int DIVIDE = 3;
const int OPER_COUNT = 4;



struct Soluter
{
	int numCount;
	int operCounts[OPER_COUNT];
	std::vector<int> numbers;
	std::vector<int> results;

	void Input()
	{
		std::cin >> numCount;

		numbers.assign(numCount, {});
		for (auto& number : numbers)
		{
			std::cin >> number;
		}

		for (int i = 0; i < OPER_COUNT; i++)
		{
			std::cin >> operCounts[i];
		}
	}

	void GetResults(int cur, int result)
	{
		if (cur == numbers.size())
		{
			results.push_back(result);
			return;
		}

		if (operCounts[PLUS] > 0)
		{
			operCounts[PLUS]--;
			GetResults(cur + 1, result + numbers[cur]);
			operCounts[PLUS]++;
		}
		if (operCounts[MINUS] > 0)
		{
			operCounts[MINUS]--;
			GetResults(cur + 1, result - numbers[cur]);
			operCounts[MINUS]++;
		}
		if (operCounts[MULITPLY] > 0)
		{
			operCounts[MULITPLY]--;
			GetResults(cur + 1, result * numbers[cur]);
			operCounts[MULITPLY]++;
		}
		if (operCounts[DIVIDE] > 0)
		{
			operCounts[DIVIDE]--;
			GetResults(cur + 1, result / numbers[cur]);
			operCounts[DIVIDE]++;
		}
	}

	void Solve()
	{
		GetResults(1, numbers[0]);
		auto minMax = std::minmax_element(std::begin(results), std::end(results));

		std::cout << *minMax.second << '\n' << *minMax.first << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}