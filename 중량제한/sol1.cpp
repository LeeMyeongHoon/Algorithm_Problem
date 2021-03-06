#ifdef 이분탐색

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

struct Data
{
	int node;
	int weight;

	Data(int n, int w) : node(n), weight(w) {}
};

struct Soluter
{
	int islandCount;
	int adjDataCount;

	std::vector<Data> adjs[10001];
	int weights[100010];

	int begin, end;

	std::vector<bool> isVisited;

	void Input()
	{
		std::ios::sync_with_stdio(false);

		scanf("%d %d", &islandCount, &adjDataCount);


		for (int i = 0; i < adjDataCount; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			adjs[a].emplace_back(b, c);
			adjs[b].emplace_back(a, c);

			weights[i] = c;
		}

		scanf("%d %d", &begin, &end);
	}

	bool HasRoute(int here, int keyWeight)
	{
		if (here == end)
		{
			return true;
		}

		bool hasRoute = false;

		for (auto& adj : adjs[here])
		{
			int next = adj.node;
			int limit = adj.weight;

			if (limit >= keyWeight)
			{
				if (!isVisited[next])
				{
					isVisited[next] = true;
					if (HasRoute(next, keyWeight))
					{
						hasRoute = true;
						break;
					}
				}
			}
		}

		return hasRoute;
	}

	void Solve()
	{
		isVisited.assign(islandCount + 1, false);

		std::sort(weights, weights + adjDataCount);

		int right = adjDataCount - 1;
		int mid;
		int left = 0;
		int result;

		while (left <= right)
		{
			isVisited[begin] = true;

			mid = (right + left) / 2;

			int limit = weights[mid];

			if (HasRoute(begin, limit))
			{
				result = limit;
				left = mid + 1;
			}

			else
			{
				right = mid - 1;
			}

			isVisited.assign(islandCount + 1, false);
		}


		std::cout << result << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}

#endif // DEBUG
