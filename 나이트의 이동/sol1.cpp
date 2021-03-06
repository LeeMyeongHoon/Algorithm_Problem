#ifdef sol1
#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int size;
	int curI, curJ;
	int keyI, keyJ;
	int minMove = INT_MAX;

	bool isVisited[300][300] = { false };

	void Input()
	{
		std::cin >> size >> curI >> curJ >> keyI >> keyJ;
	}

	void SetMin(int curI, int curJ, int curMove)
	{
		if (curI < 0 || curI >= size || curJ < 0 || curJ >= size)
		{
			return;
		}

		if (isVisited[curI][curJ])
		{
			return;
		}

		if (curMove >= minMove)
		{
			return;
		}

		if (curI == keyI && curJ == keyJ)
		{
			minMove = curMove;
		}

		isVisited[curI][curJ] = true;

		SetMin(curI - 1, curJ - 2, curMove + 1);
		SetMin(curI - 2, curJ - 1, curMove + 1);
		SetMin(curI + 1, curJ + 2, curMove + 1);
		SetMin(curI + 2, curJ + 1, curMove + 1);
		SetMin(curI - 1, curJ + 2, curMove + 1);
		SetMin(curI - 2, curJ + 1, curMove + 1);
		SetMin(curI + 1, curJ - 2, curMove + 1);
		SetMin(curI + 2, curJ - 1, curMove + 1);

		isVisited[curI][curJ] = false;
	}

	void Solve()
	{
		SetMin(curI, curJ, 0);

		std::cout << minMove << '\n';
	}
};

int main()
{
	int count;
	std::cin >> count;

	std::vector<Soluter> soluters(count);

	for (auto& soluter : soluters)
	{
		soluter.Input();
		soluter.Solve();
	}


	return 0;
}
#endif // sol1
