#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	int count;
	std::vector<int> budgets;
	int maxTotal;
	int maxBudget;

	void Input()
	{
		std::cin >> count;
		budgets.assign(count, {});
		maxBudget = -1;

		for (auto& budget : budgets)
		{
			std::cin >> budget;
			if (maxBudget < budget)
			{
				maxBudget = budget;
			}
		}
		std::cin >> maxTotal;
	}

	void Solve()
	{
		int left = 0;
		int right = maxBudget;
		int mid;
		while (left <= right)
		{
			mid = (left + right) / 2;

			int total = 0;
			for (auto& budget : budgets)
			{
				if (mid < budget)
				{
					total += mid;
				}
				else
				{
					total += budget;
				}
			}

			if (total > maxTotal)
			{
				right = mid - 1;
			}

			else if (total < maxTotal)
			{
				left = mid + 1;
			}

			else
			{
				std::cout << mid << '\n';
				return;
			}
		}

		std::cout << right << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}