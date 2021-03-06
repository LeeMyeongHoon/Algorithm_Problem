// https://www.acmicpc.net/problem/2292

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	if (n == 1)
	{
		std::cout << 1 << '\n';
	}
	else
	{
		int multi = 0;
		int offset = 1;
		int count = 2;

		for (;;)
		{
			if (n >= 2 + 6 * multi && n <= 1 + 6 * (multi + offset))
			{
				break;
			}

			multi += offset;
			offset++;
			count++;
		}

		std::cout << count << '\n';
	}

	return 0;
}