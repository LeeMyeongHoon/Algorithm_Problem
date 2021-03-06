// https://www.acmicpc.net/problem/11055

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Soluter
{
	int size;
	std::vector<int> arr;

	void Input()
	{
		std::cin >> size;
		arr.assign(size, {});

		for (auto& n : arr)
		{
			std::cin >> n;
		}
	}

	void Solve()
	{
		std::vector<int> dp(size);
		for (int back = 0; back < size; back++)
		{
			dp[back] = arr[back];
			for (int front = 0; front < back; front++)
			{
				if (arr[front] < arr[back] && dp[back] < dp[front] + arr[back])
				{
					dp[back] = dp[front] + arr[back];
				}
			}
		}

		std::cout << *std::max_element(std::begin(dp), std::end(dp)) << '\n';
	}
};

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}