#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct Soluter
{
	int vertexCount;
	int edgeCount;
	int begin;

	std::vector<std::vector<bool>> isLinked;
	std::vector<bool> isVisited;

	void Input()
	{
		std::cin >> vertexCount >> edgeCount >> begin;
		begin--;

		isLinked.assign(vertexCount, std::vector<bool>(vertexCount, false));

		for (int cnt = 0; cnt < edgeCount; cnt++)
		{
			int i, j;
			std::cin >> i >> j;
			isLinked[i - 1][j - 1] = isLinked[j - 1][i - 1] = true;
		}
	}


	void VisitBFS()
	{
		std::queue<int> q;
		q.push(begin);
		isVisited[begin] = true;

		while (q.empty() != true)
		{
			int here = q.front(); q.pop();
			std::cout << here + 1 << ' ';

			for (int next = 0; next < vertexCount; next++)
			{
				if (!isVisited[next] && isLinked[here][next])
				{
					isVisited[next] = true;
					q.push(next);
				}
			}
		}
	}

	void VisitDFS(int here)
	{
		if (isVisited[here])
		{
			return;
		}

		std::cout << here + 1 << ' ';
		isVisited[here] = true;

		for (int next = 0; next < vertexCount; next++)
		{
			if (!isVisited[next] && isLinked[here][next])
			{
				VisitDFS(next);
			}
		}
	}

	void Solve()
	{
		isVisited.assign(vertexCount, false);

		VisitDFS(begin);
		std::cout << '\n';

		isVisited.assign(vertexCount, false);

		VisitBFS();
		std::cout << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}