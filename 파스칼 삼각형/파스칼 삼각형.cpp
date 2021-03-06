#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int beginI;
	int beginJ;
	int length;
	std::vector<std::vector<int>> data;

	void Input()
	{
		std::cin >> beginI >> beginJ >> length;
	}

	void Solve()
	{
		--beginI;
		--beginJ;


		int lastI = beginI + length - 1;
		data.assign(lastI + 1, {});

		data[0].push_back(1);

		for (int i = 1; i <= lastI; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				if (j == 0 || j == i)
				{
					data[i].push_back(1);
				}
				else
				{
					data[i].push_back(data[i-1][j - 1] + data[i-1][j]);
				}
			}
		}

		int sum = 0;
		int count = 1;
		for (int i = beginI; i <= lastI; i++)
		{
			for (int j = beginJ; j < beginJ + count; j++)
			{
				sum += data[i][j];
			}
			++count;
		}

		std::cout << sum << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}