#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using Data = std::pair<int, int>;
#define DIST first
#define VERTEX second

struct Soluter
{
	int vertexCount;
	int edgeCount;
	int begin;

	std::vector<std::vector<Data>> adjs;

	void Input()
	{
		std::cin >> vertexCount >> edgeCount >> begin;

		adjs.assign(vertexCount + 1, {});
		for (int cnt = 0; cnt < edgeCount; cnt++)
		{
			int here, next, dist;
			std::cin >> here >> next >> dist;

			adjs[here].emplace_back(dist, next);
		}
	}

	static const int INF = std::numeric_limits<int>::max();
	void Solve()
	{
		std::priority_queue<Data, std::vector<Data>, std::greater<>> dists;
		std::vector<int> beginTo(vertexCount + 1, INF);
		beginTo[begin] = 0;
		dists.emplace(0, begin);

		while (dists.empty() != true)
		{
			int here = dists.top().VERTEX;
			int beginToHere = dists.top().DIST;
			dists.pop();

			if (beginToHere < beginTo[here])
			{
				continue;
			}

			for (auto& adj : adjs[here])
			{
				int next = adj.VERTEX;
				int hereToNext = adj.DIST;

				int beginToNext = beginToHere + hereToNext;
				if (beginToNext < beginTo[next])
				{
					beginTo[next] = beginToNext;
					dists.emplace(beginToNext, next);
				}
			}
		}

		for (int dst = 1; dst <= vertexCount; dst++)
		{
			if (beginTo[dst] == INF)
			{
				std::cout << "INF" << '\n';
			}
			else
			{
				std::cout << beginTo[dst] << '\n';
			}
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