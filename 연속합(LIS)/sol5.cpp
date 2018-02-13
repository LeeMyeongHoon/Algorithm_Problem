#define SOL_5
#ifdef SOL_5

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


struct Soluter
{
	int size;
	std::vector<int> nums;

	void Input()
	{
		std::cin >> size;
		nums.assign(size, 0);
		for (auto& num : nums)
		{
			std::cin >> num;
		}
	}

	void Solve()
	{
		std::vector<int> dp(size);
		dp[0] = nums[0];
		for (int i = 1; i < size; i++)
		{
			if (dp[i - 1] > 0)
			{
				dp[i] = dp[i - 1] + nums[i];
			}
			else
			{
				dp[i] = nums[i];
			}
		}

		std::cout << *std::max_element(std::begin(dp), std::end(dp)) << '\n';
	}
};


int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();
	return 0;
}
#endif // SOL_2
