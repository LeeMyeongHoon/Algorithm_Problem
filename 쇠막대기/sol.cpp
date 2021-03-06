#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>

struct Soluter
{
	std::string data;
	int s;

	void Input()
	{
		std::cin >> data;
	}

	void Solve()
	{
		int sum = 0;
		s = 0;

		for (int i = 0; i < data.size(); i++)
		{
			if (data[i] == '(')
			{
				if (data[i + 1] == ')')
				{
					i++;
					sum += s;
				}
				else
				{
					sum++;
					s++;
				}
			}

			else
			{
				s--;
			}
		}

		std::cout << sum << '\n';
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