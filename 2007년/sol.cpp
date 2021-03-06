// https://www.acmicpc.net/problem/1924

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

const int MAX_DAYS[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
const char* DAYS_STRING[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

struct Soluter
{
	int month, days;

	void Input()
	{
		std::cin >> month >> days;
	}

	void Solve()
	{
		int sum = 0;
		for (int i = 1; i <= month - 1; i++)
		{
			sum += MAX_DAYS[i];
		}
		sum += days;

		std::cout << DAYS_STRING[sum % 7] << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}