#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int num;

	void Input()
	{
		std::cin >> num;
	}

	void Solve()
	{
		int count = 0;
		int oldNum = num;

		do
		{
			int prevNum = num;
			if (num < 10)
			{
				num *= 10;
			}

			num = (num / 10) + (num % 10);
			num = (prevNum % 10) * 10 + num % 10;
			count++;

		} while (oldNum != num);

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