// https://www.acmicpc.net/problem/11403
// 플로이드-워셜 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int size;
	bool isLinked[100][100];

	void Input()
	{
		std::cin >> size;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				std::cin >> isLinked[i][j];
			}
		}
	}

	void Solve()
	{
		for (int mid = 0; mid < size; mid++)
		{
			for (int start = 0; start < size; start++)
			{
				for (int dst = 0; dst < size; dst++)
				{
					if (isLinked[start][mid] && isLinked[mid][dst])
					{
						isLinked[start][dst] = true;
					}
				}
			}
		}

		for (int start = 0; start < size; start++)
		{
			for (int dst = 0; dst < size; dst++)
			{
				std::cout << isLinked[start][dst] << ' ';
			}
			std::cout << '\n';
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