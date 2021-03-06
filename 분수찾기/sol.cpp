#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int n;

	void Input()
	{
		std::cin >> n;
	}

	void Solve()
	{
		int offsetI = -1;
		int offsetJ = +1;

		int i = +1;
		int j = -1;

		for (int count = 0; count < n; count++)
		{
			i += offsetI;
			j += offsetJ;

			if (i == -1)
			{
				i = 0;
				offsetI = +1;
				offsetJ = -1;
			}
			else if (j == -1)
			{
				j = 0;
				offsetI = -1;
				offsetJ = +1;
			}
		}

		std::cout << i + 1 << '/' << j + 1 << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}