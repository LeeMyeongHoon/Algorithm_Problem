// https://www.acmicpc.net/problem/1065

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Soluter
{
	int max;

	void Input()
	{
		std::cin >> max;
	}

	void Solve()
	{
		int count = 0;
		for (int n = 1; n <= max; n++)
		{
			std::string str = std::to_string(n);

			if (str.size() <= 2)
			{
				count++;
				continue;
			}

			bool isSeq = true;
			int dx = str[1] - str[0];
			for (int i = 1; i < str.size() - 1; i++)
			{
				if (dx != str[i + 1] - str[i])
				{
					isSeq = false;
					break;
				}
			}

			if (isSeq)
			{
				count++;
			}
		}

		std::cout << count << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}