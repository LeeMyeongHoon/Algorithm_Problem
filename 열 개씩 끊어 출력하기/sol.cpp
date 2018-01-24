#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Soluter
{
	std::string str;

	void Input()
	{
		std::cin >> str;
	}

	void Solve()
	{
		int count = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (count == 10)
			{
				count = 0;
				std::cout << '\n';
			}
			std::cout << str[i];

			count++;
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