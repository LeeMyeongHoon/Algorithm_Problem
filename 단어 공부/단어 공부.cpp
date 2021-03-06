// https://www.acmicpc.net/problem/1157

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


struct Soluter
{
	std::string str;
	int count['Z' + 1] = { 0 };

	void Input()
	{
		std::cin >> str;
	}

	void Solve()
	{
		for (auto& ch : str)
		{
			if (ch >= 'a')
			{
				count[ch - 'a' + 'A']++;
			}
			else
			{
				count[ch]++;
			}
		}

		int max = -1;
		char maxCh;
		for (int ch = 'A'; ch <= 'Z'; ch++)
		{
			if (max < count[ch])
			{
				maxCh = ch;
				max = count[ch];
			}
		}

		bool hasOverlap = false;
		for (int ch = 'A'; ch <= 'Z'; ch++)
		{
			if (max == count[ch] && ch != maxCh)
			{
				hasOverlap = true;
				break;
			}
		}

		if (hasOverlap)
		{
			std::cout << '?' << '\n';
		}
		else
		{
			std::cout << maxCh << '\n';
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