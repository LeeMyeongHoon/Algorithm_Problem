#include <iostream>
#include <algorithm>
#include <vector>

struct Pos
{
	int j;
	int vertex;

	Pos() = default;
	Pos(int v, int c) : vertex(v), j(c) {}
};

struct Soluter
{
	int edgeCount;
	int plusCount;
	int minusCount;
	int vertexCount;

	std::vector<std::vector<Pos>> adjs;

	void Input()
	{
		std::cin >> vertexCount >> plusCount >> minusCount;
		edgeCount = plusCount + minusCount;

		adjs.assign(vertexCount + 1, {});
		for (int cnt = 0; cnt < plusCount; cnt++)
		{
			int from, to, cost;
			std::cin >> from >> to >> cost;
			adjs[from].emplace_back(to, cost);
			adjs[to].emplace_back(from, cost);
		}
		for (int cnt = 0; cnt < minusCount; cnt++)
		{
			int from, to, cost;
			std::cin >> from >> to >> cost;
			adjs[from].emplace_back(to, -cost);
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
					if (beginTo[next] > beginToNext)
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

		if (hasUpdate || beginTo[1] < 0)
		{
			std::cout << "YES" << '\n';
		}
		else
		{
			std::cout << "NO" << '\n';
		}
	}
};

int main()	
{
	int count;
	std::cin >> count;
	std::vector<Soluter> soluters(count);

	for (auto& soluter : soluters)
	{
		soluter.Input();
	}

	for (auto& soluter : soluters)
	{
		soluter.Solve();
	}

	return 0;
}