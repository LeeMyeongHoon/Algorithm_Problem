#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

struct Soluter
{
	int heigth, width;
	int n;

	void Input()
	{
		std::cin >> heigth >> width >> n;
	}

	void Solve()
	{
		int floor;
		int ho;
		int remin = n % heigth;
		if (remin == 0)
		{
			ho = n / heigth;
			floor = heigth;
		}
		else
		{
			ho = n / heigth + 1;
			floor = remin;
		}
		std::cout << floor
			<< std::setw(2) << std::setfill('0') << ho << '\n';
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