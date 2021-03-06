#ifdef SOL1
// https://www.acmicpc.net/problem/2133

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int width;
	int caches[31];

	void Input()
	{
		std::cin >> width;
	}

	int GetCount(int width)
	{
		if (width == 0)
		{
			return 1;
		}

		auto& cache = caches[width];
		if (cache != -1)
		{
			return cache;

		}

		int count = 0;
		int newWidth = width - 2;
		if (newWidth >= 0)
		{
			count += (3 * GetCount(newWidth));
		}

		newWidth -= 2;
		while (newWidth >= 0)
		{
			count += (2 * GetCount(newWidth));
			newWidth -= 2;
		}

		return cache = count;
	}

	void Solve()
	{
		for (int i = 0; i <= width; i++)
		{
			caches[i] = -1;
		}

		if (width % 2 == 1)
		{
			std::cout << 0 << '\n';
		}
		else
		{
			std::cout << GetCount(width) << '\n';
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
#endif // SOL1
