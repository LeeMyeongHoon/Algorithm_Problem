#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int size;
	std::vector<std::vector<int>> data;

	void Input()
	{
		std::cin >> size;
		data.assign(size, std::vector<int>(size, 0));

		for (auto& data1 : data)
		{
			for (auto& data2 : data1)
			{
				std::cin >> data2;
			}
		}
	}

	void Solve()
	{
		for (int i = 0; i < size; i++)
		{
			int n = 0;
			for (int j = 0; j < size; j++)
			{
				n |= data[i][j];
			}
			data[i][i] = n;
		}

		for (int i = 0; i < size; i++)
		{
			std::cout << data[i][i] << ' ';
		}
		std::cout << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}