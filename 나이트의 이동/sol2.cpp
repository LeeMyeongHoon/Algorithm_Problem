#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

const int dx[8] = { +1,+1,-1,-1,+2,-2,+2,-2 };
const int dy[8] = { +2,-2,+2,-2,+1,+1,-1,-1 };

struct Data
{
	int i, j, move;
};

struct Soluter
{
	int size;
	int beginI, beginJ;
	int keyI, keyJ;

	void Input()
	{
		std::cin >> size >> beginI >> beginJ >> keyI >> keyJ;
	}

	void Solve()
	{

		std::vector<std::vector<bool>> isVisited(size, std::vector<bool>(size, false));

		std::deque<Data> queue;
		queue.push_back({ beginI, beginJ, 0 });

		for (;;)
		{
			Data data = queue.front();
			queue.pop_front();


			if (data.i == keyI && data.j == keyJ)
			{
				std::cout << data.move << '\n';
				return;
			}

			for (int i = 0; i < 8; i++)
			{
				int nextI = data.i + dy[i];
				int nextJ = data.j + dx[i];
				if (nextI >= 0 && nextJ >= 0 && nextI < size && nextJ < size && !isVisited[nextI][nextJ])
				{
					queue.push_back({ nextI, nextJ, data.move + 1 });
					isVisited[nextI][nextJ] = true;
				}
			}
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