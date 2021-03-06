#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	int a, b, c;
	int counts[10] = { 0 };
	std::cin >> a >> b >> c;

	std::string multi = std::to_string(a * b * c);

	for (auto& numChar : multi)
	{
		char numStr[2] = { numChar };
		counts[atoi(numStr)]++;
	}

	for (auto& count : counts)
	{
		std::cout << count << '\n';
	}

	return 0;
}