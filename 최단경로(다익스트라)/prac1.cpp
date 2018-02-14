#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

struct Data
{
	int cost;
	int vertex;

	Data(int vertex, int cost) : cost(cost), vertex(vertex) { }

	bool operator>(const Data& rhs) const
	{
		return this->cost > rhs.cost;
	}
};



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
			int from, adj, cost;

			std::cin >> from >> adj >> cost;

			adjs[from].emplace_back(adj, cost);
		}
	}

	const int INF = std::numeric_limits<int>::max();

	void Solve()
	{
		std::priority_queue<Data, std::vector<Data>, std::greater<>> pq;
		std::vector<int> beginTo(vertexCount + 1, INF);

		pq.emplace(begin, 0);
		beginTo[begin] = 0;

		while (!pq.empty())
		{
			int here = pq.top().vertex;
			int beginToHere = pq.top().cost;
			pq.pop();

			if (beginTo[here] < beginToHere)
			{
				continue;
			}

			for (auto& adj : adjs[here])
			{
				int next = adj.vertex;
				int hereToNext = adj.cost;

				int beginToNext = beginToHere + hereToNext;

				if (beginToNext < beginTo[next])
				{
					beginTo[next] = beginToNext;
					pq.emplace(next, beginToNext);
				}
			}

		}
		for (int i = 1; i <= vertexCount; i++)
		{
			if (beginTo[i] != INF)
			{
				std::cout << beginTo[i] << '\n';
			}
			else
			{
				std::cout << "INF" << '\n';
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