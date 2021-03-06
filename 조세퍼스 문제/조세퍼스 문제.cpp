#include <iostream>
#include <vector>
#include <algorithm>	

struct Soluter
{
	int n;
	int dx;
	std::vector<int> numbers;
	std::vector<int> results;

	void Input()
	{
		std::cin >> n >> dx;
	}

	void Solve()
	{
		numbers.assign(n + 1, {});
		for (int i = 1; i <= n; i++)
		{
			numbers[i] = i;
		}
		int ptr = 0;
		int count = n;
		for (int i = 0; i < n; i++)
		{
			ptr += dx;
			while (ptr > count)
			{
				ptr -= count;
			}

			results.push_back(numbers[ptr]);
			Remove(ptr, count);
			ptr--;
			count--;
		}

		std::cout << '<';
		for (int i = 0; i < results.size() - 1; i++)
		{
			std::cout << results[i] << ", ";
		}
		std::cout << results.back() << ">\n";
	}


	void Remove(int _th, int last)
	{
		for (int i = _th; i < last; i++)
		{
			numbers[i] = numbers[i + 1];
		}
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}