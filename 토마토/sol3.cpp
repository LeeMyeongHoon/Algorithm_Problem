#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

enum Tomato
{
	EMPTY = -1,
	INVALID = 0,
	VALID = 1
};

struct Pos
{
	int i, j, count;

	Pos() = default;
	Pos(int i, int j, int count) : i(i), j(j), count(count) {}
};

struct Soluter
{
	int endI, endJ;
	std::vector<std::vector<Tomato>> q;
	std::deque<Pos> q;

	void Input()
	{
		std::cin >> endJ >> endI;
		q.assign(endI, std::vector<Tomato>(endJ));
		for (int i = 0; i < endI; i++)
		{
			for (int j = 0; j < endJ; j++)
			{
				std::cin >> (int&)q[i][j];
				if (q[i][j] == VALID)
				{
					q.emplace_back(i, j, 0);
				}
			}
		}
	}


	void Solve()
	{
		int count = 0;
		while (!q.empty())
		{
			int i = q.front().i;
			int j = q.front().j;
			count = q.front().count;
			q.pop_front();

			auto ProcAdj = [&](int i, int j)
			{
				if (i < 0 || j < 0 || i >= endI || j >= endJ)
				{
					return;
				}

				if (q[i][j] == INVALID)
				{
					q[i][j] = VALID;
					q.emplace_back(i, j, count + 1);
				}
			};

			ProcAdj(i + 1, j);
			ProcAdj(i - 1, j);
			ProcAdj(i, j + 1);
			ProcAdj(i, j - 1);
		}

		bool isAllValid = true;
		for (int i = 0; i < endI; i++)
		{
			for (int j = 0; j < endJ; j++)
			{
				if (q[i][j] == INVALID)
				{
					isAllValid = false;
					break;
				}
			}
		}

		if (isAllValid)
		{
			std::cout << count << '\n';
		}
		else
		{
			std::cout << -1 << '\n';
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