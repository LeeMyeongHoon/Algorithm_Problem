// https://www.acmicpc.net/problem/5585

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Soluter
{
	int money;
	void Input()
	{
		int input;
		std::cin >> input;
		money = 1000 - input;
	}

	int GetCount(int money)
	{
		if (money >= 500)
		{
			return money / 500 + GetCount(money % 500);
		}

		if (money >= 100)
		{
			return money / 100 + GetCount(money % 100);
		}

		if (money >= 50)
		{
			return money / 50 + GetCount(money % 50);
		}

		if (money >= 10)
		{
			return money / 10 + GetCount(money % 10);
		}

		if (money >= 5)
		{
			return money / 5 + GetCount(money % 5);
		}

		else
		{
			return money;
		}
	}

	void Solve()
	{
		std::cout << GetCount(money) << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}