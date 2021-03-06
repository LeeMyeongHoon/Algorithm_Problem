// https://www.acmicpc.net/problem/1072

#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	long long t;
	long long w;
	long long rate;

	bool Input()
	{
		if (!(std::cin >> t >> w))
		{
			return false;
		}

		rate = w * 100 / t;

		return true;
	}

	void Solve()
	{
		if (w == t)
		{
			std::cout << -1 << '\n';
			return;
		}

		auto fP = (w * 100) / (long double)(t);
		/*long double n = 1 - (fP - (long long)fP);
		long double divider = 100 * t - 100 * w - n * t;

		if (divider <= 0)
		{
			std::cout << -1 << '\n';
			return;
		}*/

		long long iP = fP;

		long long down = 1;
		long long up = std::numeric_limits<long long>::max() / 300;
		long long result = -1;
		long long x;
		while (down <= up)
		{
			x = (down + up) / 2;
			long long newP = (w + x) * 100 / (t + x);
			if (newP > iP)
			{
				result = x;
				up = x - 1;
			}
			else
			{
				down = x + 1;
			}
		}

		std::cout << result << '\n';
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