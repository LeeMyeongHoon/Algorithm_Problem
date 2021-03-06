// https://www.acmicpc.net/problem/9461

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int n;
	std::vector<unsigned long long> data;

	void Input()
	{
		std::cin >> n;
	}

	void Solve()
	{
		if (n >= 5)
		{
			data.assign(n, {});
			data[0] = 1;
			data[1] = 1;
			data[2] = 1;
			data[3] = 2;
			data[4] = 2;

			for (int i = 5; i < n; i++)
			{
				data[i] = data[i - 5] + data[i - 1];
			}

			std::cout << data[n - 1] << '\n';
		}
		else
		{
			int num;
			switch (n)
			{
			case 1:
				num = 1;
				break;
			case 2:
				num = 1;
				break;
			case 3:
				num = 1;
				break;
			case 4:
				num = 2;
				break;
			case 5:
				num = 2;
				break;
			}

			std::cout << num << '\n';
		}
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