#ifdef sol1
// https://www.acmicpc.net/problem/1074
// 매우 느린.. 그냥 단순완전탐색...

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Soluter
{
	int size;

	int keyI;
	int keyJ;
	int count;

	bool isFinished;

	void Input()
	{
		std::cin >> size >> keyI >> keyJ;
	}

	void FindVisitCount(int size, int beginI, int beginJ)
	{
		if (isFinished)
		{
			return;
		}

		if (size == 1)
		{
			count++;
			if (beginI == keyI && beginJ == keyJ)
			{
				isFinished = true;
				return;
			}

			count++;
			if (beginI == keyI && beginJ + 1 == keyJ)
			{
				isFinished = true;
				return;
			}

			count++;
			if (beginI + 1 == keyI && beginJ == keyJ)
			{
				isFinished = true;
				return;
			}

			count++;
			if (beginI + 1 == keyI && beginJ + 1 == keyJ)
			{
				isFinished = true;
				return;
			}
		}

		else // if (size > 1)
		{
			int offset = pow(2, size - 1);

			FindVisitCount(size - 1, beginI, beginJ);
			FindVisitCount(size - 1, beginI, beginJ + offset);
			FindVisitCount(size - 1, beginI + offset, beginJ);
			FindVisitCount(size - 1, beginI + offset, beginJ + offset);
		}
	}

	void Solve()
	{
		isFinished = false;
		count = 0;
		FindVisitCount(size, 0, 0);
		// 0,0 은 방문한것이 아니다. 따라서 count - 1 출력

		std::cout << count - 1 << '\n';
	}
};

int main()
{
	Soluter soluter;

	soluter.Input();
	soluter.Solve();

	return 0;
}
#endif // sol1
