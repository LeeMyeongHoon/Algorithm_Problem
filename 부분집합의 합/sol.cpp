#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int count;
	int keySum;
	int partSet = 0;
	std::vector<int> canVisit;


	void Input()
	{
		std::cin >> count >> keySum;
		canVisit.assign(count, {});
		for (auto& num : canVisit)
		{
			std::cin >> num;
		}
	}

	void GetCount(int i, int curSum, int curSize, int preSize)
	{
		if (curSum == keySum && curSize != preSize)
		{
			partSet++;
		}

		if (i == count)
		{
			return;
		}

		GetCount(i + 1, curSum, curSize, curSize);
		GetCount(i + 1, curSum + canVisit[i], curSize + 1, curSize);
	}

	void Solve()
	{
		std::sort(std::begin(canVisit), std::end(canVisit));
		GetCount(0, 0, 0, 0);

		std::cout << partSet << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}
