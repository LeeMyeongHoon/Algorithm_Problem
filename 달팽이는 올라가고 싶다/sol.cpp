// https://www.acmicpc.net/problem/2869

#include <iostream>
#include <vector>
#include <algorithm>	

struct Soluter
{
	size_t up;
	size_t down;
	size_t height;

	void Input()
	{
		std::cin >> up >> down >> height;
	}

	void Solve()
	{
		size_t move = up - down;
		size_t day;

		if ((height-up) % move == 0)
		{
			day = (height - up) / move + 1;
		}
		else
		{
			day = (height - up) / move + 2;
		}

		std::cout << day << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}