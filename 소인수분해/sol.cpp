#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	int i = 2;
	while (n != 1)
	{
		if (n % i == 0)
		{
			std::cout << i << ' ';
			n /= i;
		}
		else
		{
			i++;
		}
	}

	std::cout << '\n';

	return 0;
}