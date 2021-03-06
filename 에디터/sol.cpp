#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


struct Soluter
{
	std::string str;
	int cur;
	int cmdCount;

	void Solve()
	{
		std::cin >> str >> cmdCount;

		cur = str.size();

		for (int i = 0; i < cmdCount; i++)
		{
			std::string cmd;
			std::cin >> cmd;

			switch (cmd[0])
			{
			case 'L':
				if (cur != 0)
				{
					cur--;
				}
				break;

			case 'D':
				if (cur != str.size())
				{
					cur++;
				}
				break;

			case 'B':
				if (cur != 0)
				{
					int target = cur - 1;
					str.erase(std::begin(str) + target);
					cur--;
				}
				break;

			case 'P':
			{
				char ch;
				std::cin >> ch;

				str.insert(std::begin(str) + cur, ch);
				
				cur++;

				break;
			}
			}
		}

		std::cout << str << '\n';	
	}
};

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	Soluter soluter;

	soluter.Solve();

	return 0;
}