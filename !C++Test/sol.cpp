#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>

int main()
{
	int count;
	std::cin >> count;

	std::vector<int> numbers(count);

	for (auto& num : numbers)
	{
		std::cin >> num;
	}

	std::priority_queue<int> pq;
	for (auto& num : numbers)
	{
		if (num != 0)
		{
			pq.push(num);
		}
		else
		{
			if (pq.empty())
			{
				std::cout << '0' << '\n';
			}
			else
			{
				std::cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}



	return 0;
}	