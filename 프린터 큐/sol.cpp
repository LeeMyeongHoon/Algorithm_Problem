#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <functional>

struct Data
{
	int id;
	int value;
};

struct Soluter
{
	int count;
	int keyId;
	std::deque<Data> q;
	std::vector<int> values;

	void Input()
	{
		std::cin >> count >> keyId;

		q.assign(count, {});
		for (int i = 0; i < count; i++)
		{
			std::cin >> q[i].value;
			values.push_back(q[i].value);

			q[i].id = i;
		}
	}

	void Solve()
	{
		int print = 0;
		std::sort(std::begin(values), std::end(values));
		while (true)
		{
			auto data = q.front();
			q.pop_front();

			if (data.value == values.back())
			{
				print++;
				values.pop_back();
				if (data.id == keyId)
				{
					break;
				}
			}
			else
			{
				q.push_back(data);
			}
		}

		std::cout << print << '\n';
	}
};

int main()
{
	int count;
	std::cin >> count;
	std::vector<Soluter> soluters(count);

	for (auto& soluter : soluters)
	{
		soluter.Input();
	}

	for (auto& soluter : soluters)
	{
		soluter.Solve();
	}

	return 0;
}