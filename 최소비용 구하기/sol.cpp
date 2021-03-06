#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

struct Pos
{
	int j;
	int vertex;

	Pos() = default;
	Pos(int v, int c) : vertex(v), j(c) {}

	bool operator>(const Pos& rhs) const
	{
		return this->j > rhs.j;
	}
};

struct Soluter
{
	int cityCount;
	int edgeCount;
	int begin;
	int end;

	std::vector<std::vector<Pos>> adjs;

	void Input()
	{
		std::cin >> cityCount >> edgeCount;

		adjs.assign(cityCount + 1, {});
		for (int cnt = 0; cnt < edgeCount; cnt++)
		{
			int from, cost, to;
			std::cin >> from >> to >> cost;

			adjs[from].emplace_back(to, cost);
		}

		std::cin >> begin >> end;
	}

	const int INF = std::numeric_limits<int>::max();

	void Solve()
	{
		std::priority_queue<Pos, std::vector<Pos>, std::greater<>> pq;
		std::vector<int> beginTo(cityCount + 1, INF);

		beginTo[begin] = 0;
		pq.emplace(begin, 0);

		while (!pq.empty())
		{
			int here = pq.top().vertex;
			int beginToHere = pq.top().j;
			pq.pop();

			if (beginToHere > beginTo[here])
			{
				continue;
			}

			for (auto& adj : adjs[here])
			{
				int next = adj.i;
				int hereToNext = adj.j;

				int beginToNext = beginToHere + hereToNext;
				if (beginToNext < beginTo[next])
				{
					beginTo[next] = beginToNext;
					pq.emplace(next, beginToNext);
				}
			}
		}

		std::cout << beginTo[end] << '\n';
	}
};


int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}