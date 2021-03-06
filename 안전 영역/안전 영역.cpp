#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int size;
	int heights[100][100];
	int rain;
	bool isVisited[100][100];

	int minHeight = std::numeric_limits<int>::max();
	int maxHeight = std::numeric_limits<int>::min();

	void Input()
	{
		std::cin >> size;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				std::cin >> heights[i][j];
				if (heights[i][j] > maxHeight)
				{
					maxHeight = heights[i][j];
				}

				if (heights[i][j] < minHeight)
				{
					minHeight = heights[i][j];
				}
			}
		}
	}

	void Reset()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				isVisited[i][j] = false;
			}
		}
	}

	void Visit(int i, int j)
	{
		if (i < 0 || i >= size || j < 0 || j >= size || heights[i][j] <= rain || isVisited[i][j])
		{
			return;
		}

		isVisited[i][j] = true;

		Visit(i + 1, j);
		Visit(i - 1, j);
		Visit(i, j + 1);
		Visit(i, j - 1);
	}

	void Solve()
	{
		int maxArea = std::numeric_limits<int>::min();
		for (rain = minHeight - 1; rain <= maxHeight; rain++)
		{
			int area = 0;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (!isVisited[i][j] && heights[i][j] > rain)
					{
						area++;
						Visit(i, j);
					}
				}
			}

			maxArea = std::max(maxArea, area);
			Reset();
		}

		std::cout << maxArea << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}