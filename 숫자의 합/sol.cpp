// https://www.acmicpc.net/problem/11720

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Soluter
{
	int n;
	std::string str;

	void Input()
	{
		std::cin >> n >> str;
	}

	void Solve()
	{
		int sum = 0;
		for (auto& numChar : str)	
		{
			sum += (numChar - '0');
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