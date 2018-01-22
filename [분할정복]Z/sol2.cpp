// https://www.acmicpc.net/problem/1074
// ���� 4���� search

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Soluter
{
	int size;

	int keyI;
	int keyJ;

	void Input()
	{
		std::cin >> size >> keyI >> keyJ;
	}

	int FindVisitCount(int size, int beginI, int beginJ)
	{
		if (size == 1)
		{
			if (beginI == keyI)
			{
				if (beginJ == keyJ)
				{
					return 1;
				}
				else
				{
					return 2;
				}
			}
			else
			{
				if (beginJ == keyJ)
				{
					return 3;
				}
				else
				{
					return 4;
				}
			}
		}

		else // if (size > 1)
		{
			int offset = pow(2, size - 1);

			if (keyI < beginI + offset) // ���κ�
			{
				if (keyJ < beginJ + offset) // ���ʺκ�
				{
					return FindVisitCount(size - 1, beginI, beginJ);
				}

				else // �����ʺκ�
				{
					return (offset * offset) + FindVisitCount(size - 1, beginI, beginJ + offset);
				}
			}

			else // �Ʒ� �κ�
			{
				if (keyJ < beginJ + offset) // ���� �κ�
				{
					return 2 * (offset * offset) + FindVisitCount(size - 1, beginI + offset, beginJ);
				}

				else // �����ʺκ�
				{
					return 3 * (offset * offset) + FindVisitCount(size - 1, beginI + offset, beginJ + offset);
				}
			}
		}
	}

	void Solve()
	{
		// 0,0 �� �湮�Ѱ��� �ƴϴ�. ���� ��ȯ������ -1 ���
		std::cout << FindVisitCount(size, 0, 0) - 1 << '\n';
	}
};

int main()
{
	Soluter soluter;

	soluter.Input();
	soluter.Solve();

	return 0;
}