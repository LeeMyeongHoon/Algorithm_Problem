#include <iostream>
#include <vector>
#include <algorithm>

struct Data
{
	int begin, end;
};

struct Soluter
{
	int n;
	std::vector<Pos> data;

	void Input()
	{
		scanf("%d", &n);

		data.assign(n, {});
		for (auto& d : data)
		{
			scanf("%d %d", &d.begin, &d.end);
		}
	}

	void Solve()
	{
		std::sort(std::begin(data), std::end(data), [](const Pos& lhs, const Pos& rhs)
		{
			if (lhs.end < rhs.end)
			{
				return true;
			}
			else if (lhs.end > rhs.end)
			{
				return false;
			}
			else
			{
				return lhs.begin < rhs.begin;
			}
		});

		int preEnd = data[0].end;
		int count = 1;
		for (int i = 1; i < n; i++)
		{
			if (preEnd <= data[i].begin)
			{
				count++;
				preEnd = data[i].end;
			}
		}

		printf("%d\n", count);
	}
};

int main()
{
	Soluter sol;
	sol.Input();
	sol.Solve();

	return 0;
}