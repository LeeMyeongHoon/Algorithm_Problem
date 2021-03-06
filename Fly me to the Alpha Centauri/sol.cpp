#include <cmath>
#include <iostream>
#include <vector>

struct Soluter
{
	int d;
	void Input()
	{
		int begin, end;
		std::cin >> begin >> end;
		d = end - begin;
	}

	void Solve()
	{
		double dMax = std::sqrt(d);
		int max = (int)dMax;

		if (max * max == d)
		{
			std::cout << 2 * max - 1 << '\n';
			return;
		}

		int count = 0;
		while (d != 0)
		{
			if (d >= max)
			{
				count += (d / max);
				d = d % max;
			}
			max--;
		}

		std::cout << count << '\n';
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