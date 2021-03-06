// https://www.acmicpc.net/problem/2257

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cassert>

int ToMass(char ch)
{
	if (ch == 'H')
	{
		return 1;
	}

	if (ch == 'C')
	{
		return 12;
	}

	if (ch == 'O')
	{
		return 16;
	}
}

bool IsAtom(char ch)
{
	return ch == 'H' || ch == 'O' || ch == 'C';
}

struct Soluter
{
	std::string data;
	std::vector<int> masses;
	int ch = 0;

	void Input()
	{
		std::cin >> data;
	}

	void Solve()
	{
		data.push_back(')');
		std::cout << GetMassSum() << '\n';
	}

	int GetMassSum()
	{
		std::vector<int> masses;
		while (data[ch] != ')')
		{
			if (IsAtom(data[ch]))
			{
				masses.push_back(ToMass(data[ch]));
			}

			else if (data[ch] == '(')
			{
				ch++;
				masses.push_back(GetMassSum());
			}

			else // 숫자인 경우
			{
				masses.back() *= (data[ch] - '0');
			}

			ch++;
		}

		return std::accumulate(std::begin(masses), std::end(masses), 0);
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}