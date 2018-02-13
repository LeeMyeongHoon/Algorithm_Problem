#ifdef MY_STANDARD
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using Data = std::pair<int, int>;
#define _dist first
#define _vertex second 
#define _vertex second

const int INF = std::numeric_limits<int>::max();

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
			int here;
			int next;
			int dist;
			std::cin >> here >> next >> dist;

			adjData[here].push_back(Data(dist, next));

		}
	}

	void Solve()
	{
		std::priority_queue<Data, std::vector<Data>, std::greater<Data>> pq;
		std::vector<int> beginTo(vertexCount + 1, INF);

		beginTo[beginV] = 0;
		pq.push(Data(beginTo[beginV], beginV));

		while (pq.empty() != true)
		{
			int beginToHere = pq.top()._dist;
			int hereV = pq.top()._vertex;
			pq.pop();

			if (beginToHere > beginTo[hereV])
			{
				continue;
			}

			// 모든 next 조사
			for (auto& adj : adjData[hereV])
			{
				int nextV = adj._vertex;
				int hereToNext = adj._dist;
				int newDist = beginToHere + hereToNext;
				if (beginTo[nextV] > newDist)
				{
					beginTo[nextV] = newDist;
					pq.push(Data(newDist, nextV));
				}
			}
		}

		for (int nextV = 1; nextV <= vertexCount; nextV++)
		{
			if (beginTo[nextV] == INF)
			{
				std::cout << "INF" << '\n';
			}
			else
			{
				std::cout << beginTo[nextV] << '\n';
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
#endif // MY_STANDARD
