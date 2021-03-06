// https://www.acmicpc.net/problem/1780
#define Sol
#ifdef Sol

#include <iostream>
#include <vector>

static size_t data[2187][2187];

struct Soluter
{

	size_t maxSize;
	size_t counts[3] = { 0 ,0,0 };

	void Input()
	{
		std::cin >> maxSize;
		for (size_t i = 0; i < maxSize; i++)
		{
			for (size_t j = 0; j < maxSize; j++)
			{
				std::cin >> data[i][j];
			}
		}
	}

	void Counting(size_t color)
	{
		counts[color + 1]++;
	}

	void SetCount(size_t beginI, size_t beginJ, size_t size)
	{
		if (size == 1)
		{
			Counting(data[beginI][beginJ]);
			return;
		}

		bool isAllSame = true;
		size_t curColor = data[beginI][beginJ];

		for (size_t i = beginI; i < beginI + size; i++)
		{
			for (size_t j = beginJ; j < beginJ + size; j++)
			{
				if (data[i][j] != curColor)
				{
					isAllSame = false;
					break;
				}
			}
			if (isAllSame == false)
			{
				break;
			}
		}

		if (isAllSame)
		{
			Counting(curColor);
		}

		else
		{
			size_t newSize = size / 3;

			SetCount(beginI, beginJ, newSize);
			SetCount(beginI, beginJ + newSize, newSize);
			SetCount(beginI, beginJ + 2 * newSize, newSize);
			SetCount(beginI + newSize, beginJ, newSize);
			SetCount(beginI + newSize, beginJ + newSize, newSize);
			SetCount(beginI + newSize, beginJ + 2 * newSize, newSize);
			SetCount(beginI + 2 * newSize, beginJ, newSize);
			SetCount(beginI + 2 * newSize, beginJ + newSize, newSize);
			SetCount(beginI + 2 * newSize, beginJ + 2 * newSize, newSize);
		}
	}

	void Solve()
	{
		SetCount(0, 0, maxSize);

		for (size_t i = 0; i < 3; i++)
		{
			std::cout << counts[i] << '\n';
		}
	}
};


size_t main()
{

	Soluter soluter;

	soluter.Input();

	soluter.Solve();

	return 0;
}

#endif

