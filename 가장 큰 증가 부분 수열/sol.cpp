// https://www.acmicpc.net/problem/11055

#include <iostream>	
#include <algorithm>
#include <vector>
#include <numeric>

int main()
{
	int size;
	std::cin >> size;

	std::vector<int> a(size);
	for (auto& number : a)
	{
		std::cin >> number;
	}

	std::vector<int> dp(size, {});

	for (int i = 0; i < size; i++)
	{
		dp[i] = a[i];
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && dp[i] < dp[j] + a[i])
			{
				dp[i] = dp[j] + a[i];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < size; i++)
	{
		ans = std::max(ans, dp[i]);
	}

	std::cout << ans << '\n';

	return 0;
}