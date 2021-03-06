// 완전탐색

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Soluter
{
	int height;
	int width;
	int result = std::numeric_limits<int>::min();

	std::string data[20];

	bool isChecked['Z' + 1] = { false };

	void Input()
	{
		std::cin >> height >> width;
		for (int i = 0; i < height; i++)
		{
			std::cin >> data[i];
		}
	}

	void Solve()
	{
		isChecked[data[0][0]] = true;
		std::cout << GetMax(0, 0) << '\n';
	}

	int GetMax(int i, int j)
	{
		int max = 1;

		isChecked[data[i][j]] = true;

		if (i + 1 < height && !isChecked[data[i + 1][j]])
		{
			max = std::max(max, 1 + GetMax(i + 1, j));
		}
		if (i - 1 >= 0 && !isChecked[data[i - 1][j]])
		{
			max = std::max(max, 1 + GetMax(i - 1, j));
		}
		if (j + 1 < width && !isChecked[data[i][j + 1]])
		{
			max = std::max(max, 1 + GetMax(i, j + 1));
		}
		if (j - 1 >= 0 && !isChecked[data[i][j - 1]])
		{
			max = std::max(max, 1 + GetMax(i, j - 1));
		}

		isChecked[data[i][j]] = false;

		return max;
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}
