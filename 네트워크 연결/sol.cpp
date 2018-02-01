// https://www.acmicpc.net/problem/1922
// 크러스컬 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>

int costs[1000][1000];
struct Soluter
{
	int comCount;
	int connetCount;

	void Input()
	{
		std::cin >> comCount >> connetCount;
		for (int com1 = 0; com1 < comCount; com1++)
		{
			for (int com2 = 0; com2 < comCount; com2++)
			{
				costs[com1][com2] = -1;
			}
		}

		for (int i = 0; i < connetCount; i++)
		{
			int com1, com2, cost;
			std::cin >> com1 >> com2 >> cost;
			costs[com1][com2] = costs[com1][com2] = cost;
		}
	}

	void Solve()
	{

	}
};
