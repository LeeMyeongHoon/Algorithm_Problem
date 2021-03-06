// https://www.acmicpc.net/problem/9012

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

struct Soluter
{
	std::string str;

	void Input()
	{
		std::cin >> str;
	}

	void Solve()
	{
		int frontCount = 0;
		bool isOK = true;
		for (auto& ch : str)
		{
			if (ch == '(')
			{
				frontCount++;
			}

			else // if (ch == ')')
			{
				if (frontCount == 0)
				{
					isOK = false;
					break;
				}
				else
				{
					frontCount--;
				}
			}
		}

		if (isOK && frontCount == 0)
		{
			std::cout << "YES" << '\n';
		}
		else
		{
			std::cout << "NO" << '\n';
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