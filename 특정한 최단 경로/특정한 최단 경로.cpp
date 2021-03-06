#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

struct Pos
{
	int vertex;
	int j;
	Pos() = default;
	Pos(int v, int c) : vertex(v), j(c) {}

	bool operator>(const Pos& rhs) const
	{
		return this->j > rhs.j;
	}
};

struct Soluter
{
	int vertexCount;
	int edgeCount;
	std::vector<std::vector<Pos>> adjs;

	int mids[2];

	void Input()
	{
		std::cin >> vertexCount >> edgeCount;
		adjs.assign(vertexCount + 1, {});
		for (int cnt = 0; cnt < edgeCount; cnt++)
		{
			int a, b, cost;
			std::cin >> a >> b >> cost;
			adjs[a].push_back(Data(b, cost));
			adjs[b].push_back(Data(a, cost));
		}

		std::cin >> mids[0] >> mids[1];
	}

	static const int INF = std::numeric_limits<int>::max();

	void Solve()
	{
		const int begin = 1;
		const int end = vertexCount;

		int beginToEnd[2] = { INF,INF };

		int beginToMid0 = GetMinCost(begin, mids[0]);
		int mid0ToMid1 = GetMinCost(mids[0], mids[1]);
		int mid1ToEnd = GetMinCost(mids[1], end);

		if (beginToMid0 != INF && mid0ToMid1 != INF && mid1ToEnd != INF)
		{
			beginToEnd[0] = beginToMid0 + mid0ToMid1 + mid1ToEnd;
		}

		int beginToMid1 = GetMinCost(begin, mids[1]);
		int mid1ToMid0 = GetMinCost(mids[1], mids[0]);
		int mid0ToEnd = GetMinCost(mids[0], end);

		if (beginToMid1 != INF && mid1ToMid0 != INF && mid0ToEnd != INF)
		{
			beginToEnd[1] = beginToMid1 + mid1ToMid0 + mid0ToEnd;
		}

		int minCost = std::min(beginToEnd[0], beginToEnd[1]);

		if (minCost == INF)
		{
			std::cout << -1 << '\n';
		}
		else
		{
			std::cout << minCost << '\n';
		}
	}

	int GetMinCost(int begin, int end)
	{
		std::vector<int> beginTo(vertexCount + 1, INF);
		std::priority_queue<Data, std::vector<Data>, std::greater<>> pq;

		beginTo[begin] = 0;
		pq.push(Data(begin, 0));

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
					pq.push(Data(next, beginToNext));
				}
			}
		}

		return beginTo[end];
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}