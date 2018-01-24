#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;

	int fibo[46] = { 0, 1 };
	for (int i = 2; i <= n; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	std::cout << fibo[n] << '\n';

	return 0;
}