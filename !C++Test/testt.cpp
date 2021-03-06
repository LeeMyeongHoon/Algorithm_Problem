#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

long long GetGCD(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}

	return GetGCD(b, a % b);
}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	long long case_;
	std::cin >> case_;
	for (long long c = 0; c < case_; c++)
	{
		long long count;
		std::cin >> count;
		std::vector<long long> arr(count);
		for (auto& n : arr)
		{
			std::cin >> n;
		}

		long long sum = 0;
		for (long long i = 0; i < count; i++)
		{
			for (long long j = i + 1; j < count; j++)
			{
				if (arr[i] < arr[j])
				{
					sum += GetGCD(arr[j], arr[i]);
				}
				else
				{
					sum += GetGCD(arr[i], arr[j]);
				}
			}
		}

		std::cout << sum << '\n';
	}

	return 0;
}