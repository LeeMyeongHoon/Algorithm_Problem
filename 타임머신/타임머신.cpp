#include <iostream>
#include <algorithm>
#include <vector>

struct Pos
{
	int j, vertex;
	Pos() = default;
	Pos(int c, int v) : j(c), vertex(v) {}
};

struct Soluter
{
	int vertexCount;
	int edgeCount;

	std::vector<std::vector<Pos>> adjs;

	void Input()
	{
		std::cin >> vertexCount >> edgeCount;
		adjs.assign(vertexCount + 1, {});
		for (int i = 0; i < edgeCount; i++)
		{
			int from, to, cost;
			std::cin >> from >> to >> cost;

			adjs[from].push_back(Pos(cost, to));
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
					int next = adj.i;
					int hereToNext = adj.j;

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

