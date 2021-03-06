// https://www.acmicpc.net/problem/1495

#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int count;
	int start;
	int max;
	std::vector<int> dx;
	std::vector<std::vector<int>> caches;

	void Input()
	{
		std::cin >> count >> start >> max;

		dx.assign(count, {});
		for (auto& d : dx)
		{
			std::cin >> d;
		}
	}

	int GetMax(int cur, int curVol)
	{
		if (curVol < 0 || curVol > max)
		{
			return -1;
		}

		if (cur == count)
		{
			return curVol;
		}

		auto& cache = caches[cur][curVol];
		if (cache != -2)
		{
			return cache;
		}

		return  cache = std::max(GetMax(cur + 1, curVol + dx[cur]), GetMax(cur + 1, curVol - dx[cur]));
	}

	void Solve()
	{
		caches.assign(count, std::vector<int>(max + 1, -2));
		std::cout << GetMax(0, start) << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}