#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

int ToNumber(char ch)
{
	if (ch >= 'A' && ch <= 'C')
	{
		return 2;
	}
	else if (ch >= 'D' && ch <= 'F')
	{
		return 3;
	}
	else if (ch >= 'G' && ch <= 'I')
	{
		return 4;
	}
	else if (ch >= 'J' && ch <= 'L')
	{
		return 5;
	}
	else if (ch >= 'M' && ch <= 'O')
	{
		return 6;
	}
	else if (ch >= 'P' && ch <= 'S')
	{
		return 7;
	}
	else if (ch >= 'T' && ch <= 'V')
	{
		return 8;
	}
	else //if (ch >= 'W' && ch <= 'Z')
	{
		return 9;
	}
}

int main()
{
	std::string str;
	std::cin >> str;

	int sum = 0;
	for (auto& ch : str)
	{
		sum += (ToNumber(ch) - 1);
	}

	sum += (str.size() * 2);

	std::cout << sum << '\n';

	return 0;
}