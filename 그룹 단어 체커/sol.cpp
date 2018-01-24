#include <iostream>
#include <algorithm>
#include <vector>
#include <string>	
#include <set>

enum Status
{
	UNCHECKED,
	CHECKED
};

struct Soluter
{
	int cnt;
	std::vector<std::string> strings;
	Status statuses['z' + 1];

	void Input()
	{
		std::cin >> cnt;
		strings.assign(cnt, {});
		for (auto& str : strings)
		{
			std::cin >> str;
		}
	}

	void Solve()
	{
		int count = 0;

		for (auto& str : strings)
		{
			for (auto& status : statuses)
			{
				status = UNCHECKED;
			}

			statuses[str[0]] = CHECKED;
			int i;
			for (i = 1; i < str.size(); i++)
			{
				if (str[i] != str[i - 1])
				{
					auto ch = str[i];
					if (statuses[ch] == CHECKED)
					{
						break;
					}
					else // if (statuses[ch] == UNCHECKED)
					{
						statuses[ch] = CHECKED;
					}
				}
			}

			if (i == str.size())
			{
				count++;
			}
		}

		std::cout << count << '\n';
	}
};

int main()
{
	Soluter soluter;

	soluter.Input();

	soluter.Solve();

	return 0;
}