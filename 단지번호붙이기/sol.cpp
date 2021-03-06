// https://www.acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

const char EMPTY = '0';
const char HOUSE = '1';

struct Soluter
{
	int size;
	std::vector<std::string> data;
	std::vector<std::vector<bool>> isCheck;

	void Input()
	{
		std::cin >> size;
		data.assign(size, {});
		for (auto& str : data)
		{
			std::cin >> str;
		}
	}

	int GetCount(int i, int j)
	{
		if (i < 0 || i >= size || j < 0 || j >= size || isCheck[i][j] || data[i][j] == EMPTY)
		{
			return 0;
		}

		else
		{
			isCheck[i][j] = true;
			return 1 + GetCount(i + 1, j) + GetCount(i, j + 1) + GetCount(i - 1, j) + GetCount(i, j - 1);
		}
	}

	void Solve()
	{
		isCheck.assign(size, std::vector<bool>(size));

		std::vector<int> counts;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int count = 0;
				count = GetCount(i, j);
				if (count != 0)
				{
					counts.push_back(count);
				}
			}
		}

		std::sort(std::begin(counts), std::end(counts));
		std::cout << counts.size() << '\n';
		for (auto& cnt : counts)
		{
			std::cout << cnt << '\n';
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