// https://www.acmicpc.net/problem/2225

#include <iostream>
#include <algorithm>
#include <vector>

long long MAX;
long long COUNT;

long long dp[201][201];

long long GetCount(long long n, long long count)
{
	if (count == COUNT)
	{
		if (n == MAX)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if (n > MAX)
	{
		return 0;
	}

	auto& cache = dp[n][count];
	if (cache != -1)
	{
		return cache;
	}

	long long ret = 0;
	for (long long i = 0; i <= MAX; i++)
	{
		ret += GetCount(n + i, count + 1);
		if (ret >= 1'000'000'000)
		{
			ret %= 1'000'000'000;
		}

	}
	return cache = ret;
}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> MAX >> COUNT;

	for (int i = 0; i < 201; i++)
	{
		for (int j = 0; j < 201; j++)
		{
			dp[i][j] = -1;
		}
	}

	std::cout << GetCount(0, 0) << '\n';

	return 0;
}