// https://www.acmicpc.net/problem/11054

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Soluter
{
	int count;
	std::vector<int> arr;
	std::vector<int> _arr;

	void Input()
	{
		std::cin >> count;
		arr.assign(count, {});
		_arr.assign(count, {});
		for (int i = 0; i < count; i++)
		{
			std::cin >> arr[i];
			_arr[count - i - 1] = arr[i];
		}
	}

	void Solve()
	{
		std::vector<int> incre(count, 1);
		std::vector<int> decre(count, 1);


		for (int back = 0; back < count; back++)
		{
			for (int front = 0; front < back; front++)
			{
				if (arr[front] < arr[back] && incre[back] < incre[front] + 1)
				{
					incre[back] = incre[front] + 1;
				}

				if (_arr[front] < _arr[back] && decre[back] < decre[front] + 1)
				{
					decre[back] = decre[front] + 1;
				}
			}
		}

		int max = -1;
		for (int i = 0; i < count; i++)
		{
			max = std::max(max, incre[i] + decre[count - i - 1]);
		}

		std::cout << max - 1 << '\n';
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
