// https://www.acmicpc.net/problem/6236

#include <iostream>
#include <vector>
#include <algorithm>

int needs[100000];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int days;
	int wantDraw;

	std::cin >> days >> wantDraw;

	for (int i = 0; i < days; i++)
	{
		std::cin >> needs[i];
	}

	int max = *std::max_element(needs, needs + days);

	int down = max;
	int up = max * days;

	while (down <= up)
	{
		int mid = (down + up) / 2;
		int cur = mid;
		int draw = 1;

		for (int i = 0; i < days; i++)
		{
			if (cur >= needs[i])
			{
				cur -= needs[i];
			}
			else
			{
				draw++;
				cur = mid - needs[i];
			}
		}

		if (draw > wantDraw)
		{
			down = mid + 1;
		}

		else /*if (draw <= wantDraw)*/
		{
			up = mid - 1;
		}
	}

	std::cout << down << '\n';

	return 0;
}