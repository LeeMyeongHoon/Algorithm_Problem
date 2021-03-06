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

		for (int bit = 0; bit < sizeof(int) * 8; ++bit)
		{
			if (n & mask)
			{
				std::cout << bit << ' ';
			}
			mask <<= 1;
		}
		std::cout << '\n';
	}


	return 0;
}