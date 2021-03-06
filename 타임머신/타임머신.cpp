#include <iostream>
#include <algorithm>
#include <vector>

struct Data
{
	int cost, vertex;
	Data() = default;
	Data(int c, int v) : cost(c), vertex(v) {}
};

struct Soluter
{
	int vertexCount;
	int edgeCount;

	std::vector<std::vector<Data>> adjs;

	void Input()
	{
		std::cin >> vertexCount >> edgeCount;
		adjs.assign(vertexCount + 1, {});
		for (int i = 0; i < edgeCount; i++)
		{
			int from, to, cost;
			std::cin >> from >> to >> cost;

			adjs[from].push_back(Data(cost, to));
		}
	}

	const int INF = std::numeric_limits<int>::max() / 2;

	void Solve()
	{
		bool hasUpdate;
		std::vector<int> beginTo(vertexCount + 1, INF);
		beginTo[1] = 0;

		for (int cnt = 0; cnt < vertexCount; cnt++)
		{
			hasUpdate = false;
			for (int here = 1; here <= vertexCount; here++)
			{
				for (auto& adj : adjs[here])
				{
					int next = adj.vertex;
					int hereToNext = adj.cost;

					int beginToNext = beginTo[here] + hereToNext;
					if (beginToNext < beginTo[next])
					{
						beginTo[next] = beginToNext;
						hasUpdate = true;
					}
				}
			}
			if (!hasUpdate)
			{
				break;
			}
		}


		if (hasUpdate)
		{
			std::cout << "-1" << '\n';
		}

		else
		{
			for (int i = 2; i <= vertexCount; i++)
			{
				if (beginTo[i] == INF)
				{
					std::cout << "-1" << '\n';
				}
				else
				{
					std::cout << beginTo[i] << '\n';
				}
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

