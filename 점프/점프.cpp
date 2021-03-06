#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	size_t size;
	int nums[100][100];
	long long caches[100][100];

	void Input()
	{
		std::cin >> size;
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				std::cin >> nums[i][j];
			}
		}
	}

	size_t GetCount(size_t i, size_t j)
	{
		if (i >= size || j >= size)
		{
			return 0;
		}

		if (i == size - 1 && j == size - 1)
		{
			return 1;
		}
		auto& cache = caches[i][j];
		if (cache != -1)
		{
			return cache;
		}

		if (nums[i][j] == 0)
		{
			return cache = 0;
		}



		return cache = GetCount(i + nums[i][j], j) + GetCount(i, j + nums[i][j]);
	}

	void Solve()
	{
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				caches[i][j] = -1;
			}
		}

		std::cout << GetCount(0, 0) << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}