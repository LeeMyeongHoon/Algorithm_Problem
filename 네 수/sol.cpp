// https://www.acmicpc.net/problem/10824

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Soluter
{
	std::string str[4];

	void Input()
	{
		for (int i = 0; i < 4; i++)
		{
			std::cin >> str[i];
		}
	}

	void Solve()
	{
		std::string str1 = str[0] + str[1];
		auto op1 = std::atol(str1.data());

		std::string str2 = str[2] + str[3];
		auto op2 = std::atol(str2.data());

		std::cout << op1 + op2 << '\n';
	}
};

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}