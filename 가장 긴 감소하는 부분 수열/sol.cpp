// https://www.acmicpc.net/problem/11053

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int size;

	std::cin >> size;

	std::vector<int> arr(size);
	for (auto& n : arr)
	{
		std::cin >> n;
	}

	std::vector<int> dp(size, 1);

	for (int back = 1; back < size; back++)
	{
		for (int front = 0; front < back; front++)
		{
			if (arr[front] > arr[back] && dp[back] < dp[front] + 1)
			{
				dp[back] = dp[front] + 1;
			}
		}
	}

	std::cout << *std::max_element(std::begin(dp), std::end(dp)) << '\n';

	return 0;
}