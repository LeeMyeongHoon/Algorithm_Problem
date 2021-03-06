#include <iostream>
#include <vector>
#include <algorithm>

int GetGCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	return GetGCD(b, a%b);
}

int main()
{
	int a, b;
	std::cin >> a >> b;

	if (b < a)
	{
		std::swap(a, b);
	}

	int gcd = GetGCD(a, b);
	int lcm = (a) * (b) / (gcd);

	std::cout << gcd << '\n'
		<< lcm << '\n';

	return 0;
}