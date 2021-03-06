#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Soluter
{
	std::string data;

	void Input()
	{
		std::cin >> data;
	}

	void Solve()
	{
		int count = (data[0] == 'O' ? 1 : 0);
		int sum = count;
		for (int i = 1; i < data.size(); i++)
		{
			if (data[i] == 'O')
			{
				if (data[i - 1] == 'O')
				{
					count++;
				}
				else
				{
					count = 1;
				}
				sum += count;
			}
			else
			{
				count = 0;
			}
		}

		std::cout << sum << '\n';
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