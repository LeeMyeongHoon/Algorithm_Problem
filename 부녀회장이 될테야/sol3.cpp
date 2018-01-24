// 반복적 동적계획법
#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int k, totalN;
	int caches[15][15] = { 0 };

	void Input()
	{
		std::cin >> k >> totalN;
	}

	void Solve()
	{
		for (int b = 1; b <= totalN; b++)
		{
			caches[0][b] = b;
		}

		for (int a = 1; a <= k - 1; a++)
		{
			for (int b = 1; b <= totalN; b++)
			{
				for (int i = 1; i <= b; i++)
				{
					caches[a][b] += caches[a - 1][i];
				}
			}
		}

		for (int i = 1; i <= totalN; i++)
		{
			caches[k][totalN] += caches[k - 1][i];
		}

		std::cout << caches[k][totalN] << '\n';
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
