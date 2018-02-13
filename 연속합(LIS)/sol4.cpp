#ifdef 성공했으나 아직 많이느림
#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int size;
	std::vector<int> sums;
	std::vector<int> keyIndexes;
	std::vector<int> nums;

	int GetSum(int begin, int end)
	{
		if (begin == 0)
		{
			return sums[end];
		}
		else
		{
			return sums[end] - sums[begin - 1];
		}
	}

	void Input()
	{
		std::cin >> size;
		sums.assign(size, {});
		nums.assign(size, {});
		bool hasPrePositive = false;

		std::cin >> nums[0];
		sums[0] = nums[0];


		if (sums[0] >= 0)
		{
			hasPrePositive = true;
		}

		keyIndexes.push_back(0);

		for (int i = 1; i < size; i++)
		{
			std::cin >> nums[i];
			sums[i] = sums[i - 1] + nums[i];

			if (hasPrePositive)
			{
				if (nums[i] < 0)
				{
					keyIndexes.push_back(i);
					hasPrePositive = false;
				}
			}
			else if (nums[i] >= 0)
			{
				keyIndexes.push_back(i);
				hasPrePositive = true;
			}
		}

		keyIndexes.push_back(size);
	}

	void Solve()
	{
		if (keyIndexes.size() == 2)
		{
			if (nums[0] >= 0)
			{
				std::cout << sums[size - 1] << '\n';
			}
			else
			{
				std::cout << *std::max_element(std::begin(nums), std::end(nums)) << '\n';
			}
			return;
		}

		int front;
		if (nums[0] >= 0)
		{
			front = 0;
		}
		else
		{
			front = 1;
		}

		int max = std::numeric_limits<int>::min();
		for (; front < keyIndexes.size(); front += 2)
		{
			for (int back = front + 1; back < keyIndexes.size(); back += 2)
			{
				max = std::max(max, GetSum(keyIndexes[front], keyIndexes[back] - 1));
			}
		}

		std::cout << max << '\n';
	}
};

int main()
{
	std::ios::sync_with_stdio(false);

	Soluter soluter;
	soluter.Input();
	soluter.Solve();
	return 0;
}

#endif // 성공했으나 아직 느림
