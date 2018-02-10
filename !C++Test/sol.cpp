#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <bitset>

int main()
{
	int count;
	std::cin >> count;

	for (int cnt = 0; cnt < count; cnt++)
	{
		int n;
		std::cin >> n;

		int mask = 1;
		for (int i = 0; i < sizeof(int) * 8; i++)
		{
			if (n & mask)
			{
				std::cout << i << ' ';
			}
			mask <<= 1;
		}
		std::cout << '\n';
	}


	return 0;
}