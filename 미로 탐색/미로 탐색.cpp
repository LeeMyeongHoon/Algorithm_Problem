#include <iostream>
#include <algorithm>
#include <vector>
#include <string>	
#include <deque>

struct Diff
{
	int i, j;
};

const Diff diff[4] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

struct Pos2D
{
	int i, j, route;
};

struct Soluter
{
	int endI, endJ;
	std::string nums[100];

	void Input()
	{
		std::cin >> endI >> endJ;
		for (int i = 0; i < endI; i++)
		{
			std::cin >> data[i];
		}
	}

	void Solve()
	{
		std::deque<Pos2D> q;
		q.push_back({ 0,0,1 });
		data[0][0] = '0';

		while (true)
		{
			Pos2D pos = q.front();
			q.pop_front();

			if (pos.i == endI - 1 && pos.j == endJ - 1)
			{
				std::cout << pos.route << '\n';
				return;
			}

			for (auto& d : diff)
			{
				int nextI = pos.i + d.i;
				int nextJ = pos.j + d.j;
				if (nextI >= 0 && nextI < endI && nextJ >= 0 && nextJ < endJ && data[nextI][nextJ] == '1')
				{
					q.push_back({ nextI, nextJ, pos.route + 1 });
					nums[nextI][nextJ] = '0';
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