#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Cmd
{
	int a, b, c;
};

struct UnionFindSet
{
	std::vector<int> parent;
	std::vector<int> rank;

	UnionFindSet(int size)
		:parent(size), rank(size)
	{
		for (int i = 0; i < size; i++)
		{
			parent[i] = i;
		}
	}

	int Find(int u)
	{
		if (parent[u] == u)
		{
			return u;
		}

		return parent[u] = Find(parent[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
		{
			return;
		}

		if (rank[v] > rank[u])
		{
			std::swap(u, v);
		}

		parent[v] = u;
		if (rank[v] == rank[u])
		{
			rank[u]++;
		}
	}
};

struct Soluter
{
	int n, m;
	std::vector<Cmd> cmds;


	void Input()
	{
		std::cin >> n >> m;
		cmds.assign(m, {});
		for (auto& cmd : cmds)
		{
			std::cin >> cmd.a >> cmd.b >> cmd.c;
		}
	}

	void Solve()
	{
		UnionFindSet ufSet(n + 1);

		for (auto& cmd : cmds)
		{
			if (cmd.a == 0)
			{
				ufSet.Merge(cmd.b, cmd.c);
			}
			else
			{
				if (ufSet.Find(cmd.b) == ufSet.Find(cmd.c))
				{
					std::cout << "YES" << '\n';
				}
				else
				{
					std::cout << "NO" << '\n';
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