#define LIST_이용
#ifdef LIST_이용
#include <iostream>
#include <algorithm>
#include <vector>	
#include <array>
#include <iomanip>
#include <list>

constexpr auto INF = std::numeric_limits<double>::max();

struct Soluter
{
	std::list<double> list;

	void Sove()
	{
		list = { INF,INF,INF ,INF ,INF ,INF ,INF };

		int count;
		scanf("%d", &count);
		for (int i = 0; i < count; i++)
		{
			double num;
			scanf("%lf", &num);
			auto iter = std::upper_bound(std::begin(list), std::end(list), num);
			if (iter == std::end(list))
			{
				continue;
			}

			list.insert(iter, num);
			list.pop_back();
		}

		for (auto& num : list)
		{
			std::cout << std::fixed << std::setprecision(3) << num << '\n';
		}
	}
};

int main()
{
	Soluter soluter;
	soluter.Sove();

	return 0;
}
#endif // LIST 이용
