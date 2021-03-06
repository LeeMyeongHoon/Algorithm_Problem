// https://www.acmicpc.net/problem/2011

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Soluter
{
	std::string data;
	std::vector<long long> caches;

	void Input()
	{
		std::cin >> data;
	}

	long long GetCount(long long cur)
	{
		if (cur == data.size())
		{
			return 1;
		}

		auto& cache = caches[cur];
		if (cache != -1)
		{
			return cache;
		}

		long long ret = 0;

		if (data[cur] > '0')
		{
			ret += GetCount(cur + 1);
			if (ret >= 1'000'000)
			{
				ret %= 1'000'000;
			}

		}

		if (cur + 1 < data.size())
		{
			long long a = data[cur] - '0';
			long long b = data[cur + 1] - '0';

			long long n = a * 10 + b;

			if (10 <= n && n <= 26)
			{
				ret += GetCount(cur + 2);

				if (ret >= 1'000'000)
				{
					ret %= 1'000'000;
				}
			}
		}

		return cache = (ret %= 1'000'000);
	}

	void Solve()
	{
		caches.assign(data.size(), -1);

		std::cout << GetCount(0) << '\n';
	}
};

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}