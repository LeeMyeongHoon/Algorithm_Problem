// https://www.acmicpc.net/problem/2504

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

int result = 0;
std::string str;

bool IsOk()
{
	int multi = 1;
	std::stack<int> stack;

	for (int i = 0; i < str.size(); i++)
	{
		char ch = str[i];
		if (ch == '(')
		{
			multi *= 2;
			stack.push(ch);
			if (str[i+1] == ')')
			{
				result += multi;
			}
		}
		else if (ch == '[')
		{
			multi *= 3;
			stack.push(ch);
			if (str[i + 1] == ']')
			{
				result += multi;
			}
		}
		else if (ch == ')')
		{
			if (stack.empty() || stack.top() != '(')
			{
				return false;
			}

			stack.pop();
			multi /= 2;
		}
		else if (ch == ']')
		{
			if (stack.empty() || stack.top() != '[')
			{
				return false;
			}
			stack.pop();
			multi /= 3;
		}
	}

	if (stack.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	std::cin >> str;

	if (IsOk())
	{
		std::cout << result << '\n';
	}
	else
	{
		std::cout << 0 << '\n';
	}


	return 0;
}