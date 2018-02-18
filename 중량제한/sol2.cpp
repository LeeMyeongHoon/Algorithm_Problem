#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

const int INF = std::numeric_limits<int>::max() / 2;

struct Data
{
	int node;
	int weight;

	Data() = default;
	Data(int n, int w) : node(n), weight(w) { }

	bool operator<(const Data& rhs) const
	{
		return this->weight < rhs.weight;
	}
};

struct Soluter
{
	int islandCount;
	int adjDatdCount;

	std::vector<std::vector<Data>> adjs;

	int begin;
	int end;

	void Input()
	{
		std::cin >> islandCount >> adjDatdCount;	

		adjs.assign(islandCount + 1, {});
		for (int i = 0; i < adjDatdCount; i++)
		{
			int a, b, c;
			std::cin >> a >> b >> c;

			adjs[a].emplace_back(b, c);
			adjs[b].emplace_back(a, c);
		}

		std::cin >> begin >> end;
	}

	void Solve()
	{
		std::vector<int> beginTo(islandCount + 1, 0);

		std::priority_queue<Data> pq;
		pq.emplace(begin, INF);
		while (!pq.empty())
		{
			int here = pq.top().node;
			int beginToHere = pq.top().weight;
			pq.pop();

			if (here == end)
			{
				continue;
			}

			if (beginToHere < beginTo[here])
			{
				continue;
			}

			for (auto& adj : adjs[here])
			{
				int next = adj.node;
				int hereToNext = adj.weight;

				int beginToNext = std::min(beginToHere, hereToNext);
				if (beginToNext > beginTo[next])
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