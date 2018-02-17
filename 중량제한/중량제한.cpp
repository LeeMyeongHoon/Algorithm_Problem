#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct Pos
{
	int i;
	int j;

	Pos(int i, int j) : i(i), j(j) { }
};

struct Data
{
	int island;
	int weight;
	Data() = default;
	Data(int island, int weight) : island(island), weight(weight) { }
};

struct Soluter
{
	int islandCount;
	int adjDataCount;
	std::vector<std::vector<Data>> adjs;
	std::vector<bool> isVisited;

	int maxWeight = -1;
	int minWeight = std::numeric_limits<int>::max();
	int begin;
	int end;

	void Input()
	{
		std::cin >> islandCount >> adjDataCount;

		adjs.assign(islandCount + 1, {});

		for (int i = 0; i < adjDataCount; i++)
		{
			int a, b, c;
			std::cin >> a >> b >> c;
			adjs[a].emplace_back(b, c);
			adjs[b].emplace_back(a, c);

			if (c > maxWeight)
			{
				maxWeight = c;
			}

			if (c < minWeight)
			{
				minWeight = c;
			}
		}

		std::cin >> begin >> end;
	}

	bool HasRoute(int here, int limit)
	{
		if (here == end)
		{
			return true;
		}

		if (isVisited[here])
		{
			return false;
		}

		isVisited[here] = true;

		bool hasRoute = false;
		for (auto& adj : adjs[here])
		{
			int next = adj.island;
			int weight = adj.weight;

			if (weight <= limit)
			{
				if (HasRoute(next, limit))
				{
					hasRoute = true;
					break;
				}
			}
		}

		isVisited[here] = false;

		return hasRoute;
	}

	void Solve()
	{
		isVisited.assign(islandCount + 1, false);

		int midLimit;
		int downLimit = minWeight;
		int upLimit = maxWeight;

		while (downLimit <= upLimit)
		{
			if (upLimit - downLimit == 1)
			{
				if (HasRoute(begin, upLimit))
				{
					downLimit = upLimit;
				}
				break;
			}

			midLimit = (downLimit + upLimit) / 2;

			if (HasRoute(begin, midLimit))
			{
				downLimit = midLimit;
			}
			else
			{
				upLimit = midLimit - 1;
			}
		}

		std::cout << downLimit << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}