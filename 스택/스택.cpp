// https://www.acmicpc.net/problem/10828

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

int main()
{
	int n;
	std::cin >> n;

	std::stack<int> stack;
	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;
		if (str == "push")
		{
			int num;
			std::cin >> num;
			stack.push(num);
		}
		else if (str == "pop")
		{
			if (!stack.empty())
			{
				int num = stack.top();
				stack.pop();
				std::cout << num << '\n';
			}
			else
			{
				std::cout << -1 << '\n';
			}
		}
		else if (str == "size")
		{
			std::cout << stack.size() << '\n';
		}
		else if (str == "empty")
		{
			if (stack.empty())
			{
				std::cout << 1 << '\n';
			}
			else
			{
				std::cout << 0 << '\n';
			}
		}
		else if (str == "top")
		{
			if (!stack.empty())
			{
				int num = stack.top();
				std::cout << num << '\n';
			}
			else
			{
				std::cout << -1 << '\n';
			}
		}
	}

	return 0;
}