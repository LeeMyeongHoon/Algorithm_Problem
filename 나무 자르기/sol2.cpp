#ifdef 이분탐색
// https://www.acmicpc.net/problem/2805

#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	size_t target;
	int treeCount;

	std::vector<int> heights;

	void Input()
	{
		std::cin >> treeCount >> target;

		heights.assign(treeCount, {});

		for (auto& height : heights)
		{
			std::cin >> height;
		}
	}

	void Solve()
	{
		int down = 0;
		int up = *std::max_element(std::begin(heights), std::end(heights));
		int cut;
		int result;
		while (down <= up)
		{
			cut = (up + down) / 2;

			size_t sum = 0;
			for (auto& height : heights)
			{
				if (height > cut)
				{
					sum += (height - cut);
				}
			}

			if (sum > target)
			{
				result = cut;
				down = cut + 1;
			}

			else if (sum < target)
			{
				up = cut - 1;
			}

			else if (sum == target)
			{
				result = cut;
				break;
			}
		}

		std::cout << result << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}
#endif // 이부남색
