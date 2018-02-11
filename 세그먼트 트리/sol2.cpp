#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define mid ((begin+end)/2)
struct SegmentTree
{
	std::vector<size_t> data;
	std::vector<size_t> tree;

	size_t Init(int node, int begin, int end)
	{
		if (begin == end)
		{
			return tree[node] = data[begin];
		}

		return tree[node] = Init(node * 2, begin, mid) + Init(node * 2 + 1, mid + 1, end);
	}

	void Init()
	{
		tree.assign(4 * data.size(), {});
		Init(1, 0, data.size() - 1);
	}

	size_t Sum(int node, int begin, int end, int left, int right)
	{
		if (end < left || right < begin)
		{
			return 0;
		}

		if (left <= begin && end <= right)
		{
			return tree[node];
		}

		return Sum(node * 2, begin, mid, left, right) + Sum(node * 2 + 1, mid + 1, end, left, right);
	}

	size_t Sum(int left, int right)
	{
		return Sum(1, 0, data.size() - 1, left, right);
	}

	void Modify(int node, int begin, int end, int index, int diff)
	{
		if (index < begin || end < index)
		{
			return;
		}
		tree[node] += diff;

		if (begin == end)
		{
			return;
		}

		Modify(node * 2, begin, mid, index, diff);
		Modify(node * 2 + 1, mid + 1, end, index, diff);
	}

	void Modify(int index, int newNum)
	{
		int diff = newNum - data[index];
		data[index] = newNum;
		Modify(1, 0, data.size() - 1, index, diff);
	}
};

struct Cmd
{
	int a, b, c;
};

struct Soluter
{
	int numCount;
	int modifyCount;
	int sumCount;

	std::vector<Cmd> cmds;
	SegmentTree tree;

	void Input()
	{
		std::cin >> numCount >> modifyCount >> sumCount;
		tree.data.assign(numCount, {});

		for (auto& num : tree.data)
		{
			std::cin >> num;
		}


		cmds.assign(modifyCount + sumCount, {});
		for (auto& cmd : cmds)
		{
			std::cin >> cmd.a >> cmd.b >> cmd.c;
		}
	}

	void Solve()
	{
		tree.Init();
		for (auto& cmd : cmds)
		{
			if (cmd.a == 1)
			{
				tree.Modify(cmd.b - 1, cmd.c);
			}
			else
			{
				std::cout << tree.Sum(cmd.b - 1, cmd.c - 1) << '\n';
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