#include <iostream>
#include <vector>
#include <algorithm>

int history[500][500];
int data[500][500];
struct Soluter
{
	int size;

	void Input()
	{
		std::cin >> size;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				std::cin >> data[i][j];
			}
		}
	}

	int GetMaxSurvivingDay(int i, int j)
	{
		if (i < 0 || i >= size || j < 0 || j >= size)
		{
			return 0;
		}

		auto& cache = history[i][j];

		if (cache != -1)
		{
			return cache;
		}

		int day = 0;
		int prevData = data[i][j];

		if (data[i + 1][j] > prevData)
		{
			day = std::max(day, 1 + GetMaxSurvivingDay(i + 1, j));
		}
		if (data[i - 1][j] > prevData)
		{
			day = std::max(day, 1 + GetMaxSurvivingDay(i - 1, j));
		}
		if (data[i][j + 1] > prevData)
		{
			day = std::max(day, 1 + GetMaxSurvivingDay(i, j + 1));
		}
		if (data[i][j - 1] > prevData)
		{
			day = std::max(day, 1 + GetMaxSurvivingDay(i, j - 1));
		}

		return cache = day;
	}

	void Solve()
	{
		for (auto& history1 : history)
		{
			for (auto& history2 : history1)
			{
				history2 = -1;
			}
		}

		int maxDay = std::numeric_limits<int>::min();

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				maxDay = std::max(maxDay, 1 + GetMaxSurvivingDay(i, j));
			}
		}

		std::cout << maxDay << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();

	soluter.Solve();

	return 0;
}