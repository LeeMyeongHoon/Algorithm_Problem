#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int count;
	std::cin >> count;

	std::vector<int> numbers(count);
	for (auto& n : numbers)
	{
		std::cin >> n;
	}

	std::vector<int> dp(count);
	for (int back = 0; back < count; back++)
	{
		dp[back] = numbers[back];
		for (int i = 0; i < back; i++)
		{
			if (numbers[i] < numbers[back] && dp[back] < dp[i] + numbers[back])
			{
				dp[back] = dp[i] + numbers[back];
			}
		}
	}

	std::cout << *std::max_element(std::begin(dp), std::end(dp)) << '\n';

	return 0;
}