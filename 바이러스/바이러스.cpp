// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int n;
	bool isLinked[101][101] = { false };
	bool isVisited[101] = { false };
	int count = 0;

	void Input()
	{
		int link;
		std::cin >> n >> link;

		for (int i = 0; i < link; i++)
		{
			int v, u;
			std::cin >> v >> u;

			isLinked[v][u] = true;
			isLinked[u][v] = true;
		}
	}

	void SetCount(int here)
	{
		isVisited[here] = true;
		for (int next = 1; next <= n; next++)
		{
			if (isLinked[here][next] && !isVisited[next])
			{
				count++;
				SetCount(next);
			}
		}
	}

	void Solve()
	{
		SetCount(1);

		std::cout << count << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}