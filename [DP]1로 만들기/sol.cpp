#ifdef 재귀적동적계획법
// https://www.acmicpc.net/problem/1463
// 재귀적 동적계획법
#include <iostream>
#include <vector>
#include <algorithm>

int history[1000000];
struct Soluter
{
	int num;

	void Input()
	{
		std::cin >> num;
	}

	void Solve()
	{
		for (int i = 0; i < num + 1; i++)
		{
			history[i] = -1;
		}

		std::cout << GetMinCount(num) << '\n';
	}

	int GetMinCount(int num)
	{
		if (num == 1)
		{
			return 0;
		}

		auto& cache = history[num];

		if (cache != -1)
		{
			return cache;
		}

		int minCount = std::numeric_limits<int>::max();

		if (num % 3 == 0)
		{
			minCount = 1 + GetMinCount(num / 3);
		}
		if (num % 2 == 0)
		{
			minCount = std::min(minCount, 1 + GetMinCount(num / 2));
		}

		minCount = std::min(minCount, 1 + GetMinCount(num - 1));

		return cache = minCount;
	}
};

int main()
{
	Soluter soluter;

	soluter.Input();
	soluter.Solve();


	return 0;
}
#endif // 재귀적동적계획법
