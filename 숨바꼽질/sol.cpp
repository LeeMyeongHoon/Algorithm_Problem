#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

struct Data
{
	int cur;
	int count;

	Data(int cur, int count) : cur(cur), count(count) {}
};

struct Soluter
{
	int cur;
	int end;

	void Input()
	{
		std::cin >> cur >> end;
	}

	void Solve()
	{
		std::queue<Pos> q;
		std::vector<bool> isVisited(200000, false);
		q.emplace(cur, 0);


		while (true)
		{
			int cur = q.front().cur;
			int count = q.front().count;
			q.pop();

			isVisited[cur] = true;

			if (cur == end)
			{
				std::cout << count << '\n';
				return;
			}

			if (cur - 1 >= 0 && !isVisited[cur - 1])
			{
				q.emplace(cur - 1, count + 1);
			}

			if (cur < end)
			{
				if (!isVisited[cur + 1])
				{
					q.emplace(cur + 1, count + 1);
				}

				if (cur != 0 && !isVisited[cur * 2])
				{
					q.emplace(cur * 2, count + 1);
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