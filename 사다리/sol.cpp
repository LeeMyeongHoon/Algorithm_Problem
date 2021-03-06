// https://www.acmicpc.net/problem/2022

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

struct Soluter
{
	long double x, y, c;

	bool Input()
	{
		if ((std::cin >> x >> y >> c))
		{
			return true;
		}

		return false;
	}

	void Solve()
	{
		long double down = 0.0001L;
		long double up = std::max(x, y) - 0.0001L;

		while (down <= up)
		{
			auto t = (down + up) / 2;

			auto op1 = x - t;
			auto op2 = x + t;
			auto op3 = y - t;
			auto op4 = y + t;

			auto _c = sqrt(op1*op2*op3*op4) / (sqrt(op1*op2) + sqrt(op3*op4));
			if (_c >= c)
			{
				down = t + 0.0001;
			}
			else
			{
				up = t - 0.0001;
			}
		}

		std::cout << std::fixed << std::setprecision(3) << down << '\n';
	}
};

int main()
{
	while (true)
	{
		Soluter soluter;
		if (!soluter.Input())
		{
			break;
		}
		soluter.Solve();
	}

	return 0;
}