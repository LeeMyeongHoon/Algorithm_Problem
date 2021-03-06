#ifdef sol
// https://www.acmicpc.net/problem/11403
// 완전탐색인데 동적계획적용하기 불가능

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	bool isLinked[100][100];
	bool isVisited[100];
	int size;

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

	void Init()
	{
		for (int i = 0; i < size; i++)
		{
			isVisited[i] = false;
		}
	}

	bool HasRoute(int start, int dst)
	{
		if (isLinked[start][dst])
		{
			return true;
		}

		for (int mid = 0; mid < size; mid++)
		{
			if (isLinked[start][mid] && !isVisited[mid])
			{
				isVisited[mid] = true;
				if (HasRoute(mid, dst))
				{
					return true;
				}
				isVisited[mid] = false;
			}
		}

		return false;
	}

	void Solve()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				Init();
				std::cout << HasRoute(i, j) << ' ';
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
#endif // SOL1
