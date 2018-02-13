#ifdef prac1
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
	int beginV;

	std::vector<std::vector<Data>> adjData;

	void Input()
	{
		std::cin >> vertexCount >> edgeCount >> beginV;

		adjData.assign(vertexCount + 1, {});
		for (int cnt = 0; cnt < edgeCount; cnt++)
		{
			int here, next, dist;
			std::cin >> here >> next >> dist;
			adjData[here].push_back(Data(dist, next));
		}
	}

	const int INF = std::numeric_limits<int>::max();
	void Solve()
	{
		std::priority_queue<Data> dists;
		std::vector<int> beginTo(vertexCount + 1, INF);
		dists.push(Data(0, beginV));
		while (dists.empty() != true)
		{
			int here = dists.top().VERTEX;
			int beginToHere = dists.top().DIST;
			dists.pop();

			if (beginToHere > beginTo[here])
			{
				continue;
			}

			for (auto& adj : adjData[here])
			{
				int nextV = adj.VERTEX;
				int hereToNext = adj.DIST;

				int newDist = beginToHere + hereToNext;
				if (newDist < beginTo[nextV])
				{
					beginTo[nextV] = newDist;
					dists.push(Data(newDist, nextV));
				}
			}
		}

		for (int dstV = 1; dstV <= vertexCount; dstV++)
		{
			if (beginTo[dstV] == INF)
			{
				std::cout << "INF" << '\n';
			}
			else
			{
				std::cout << beginTo[dstV] << '\n';
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
#endif // prac1
