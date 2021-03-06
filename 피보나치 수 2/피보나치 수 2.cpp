// https://www.acmicpc.net/problem/2748

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;

	std::cin >> n;

	std::vector<int64_t> dp(n + 1);

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	std::cout << dp[n] << '\n';

	return 0;
}