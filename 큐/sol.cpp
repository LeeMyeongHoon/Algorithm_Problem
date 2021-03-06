#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

int main()
{
	int count;
	std::cin >> count;
	std::queue<int> queue;

	for (int i = 0; i < count; i++)
	{
		std::string str;
		int num;
		std::cin >> str;

		if (str == "push")
		{
			std::cin >> num;
			queue.push(num);
		}

		else if (str == "pop")
		{
			if (queue.empty())
			{
				std::cout << -1 << '\n';
			}
			else
			{
				num = queue.front();
				queue.pop();
				std::cout << num << '\n';
			}
		}

		else if (str == "size")
		{
			std::cout << queue.size() << '\n';
		}

		else if (str == "empty")
		{
			if (queue.empty())
			{
				std::cout << 1 << '\n';
			}
			else
			{
				std::cout << 0 << '\n';
			}
		}

		else if (str == "front")
		{
			if (queue.empty())
			{
				std::cout << -1 << '\n';
			}
			else
			{
				std::cout << queue.front() << '\n';
			}
		}

		else if (str == "back")
		{
			if (queue.empty())
			{
				std::cout << -1 << '\n';
			}
			else
			{
				std::cout << queue.back() << '\n';
			}
		}
		else
		{
		}
	}

	return 0;
}