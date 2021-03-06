// https://www.acmicpc.net/problem/2912

#include <iostream>
#include <algorithm>
#include <vector>

struct Range
{
	int begin;
	int end;

	Range() = default;
};

struct Soluter
{
	int people;
	int colorKinds;

	std::vector<int> colors;

	int caseCount;
	std::vector<Range> ranges;

	void Input()
	{
		scanf("%d %d", &people, &colorKinds);

		colors.assign(people + 1, {});
		for (int i = 1; i <= people; i++)
		{
			scanf("%d", &colors[i]);
		}

		std::cin >> caseCount;
		ranges.assign(caseCount, {});
		for (auto& range : ranges)
		{
			scanf("%d %d", &range.begin, &range.end);
		}
	}

	void Solve()
	{
		for (auto& range : ranges)
		{
			int begin = range.begin;
			int end = range.end;
			std::vector<int> counts(colorKinds + 1, 0);

			for (int person = begin; person <= end; ++person)
			{	
				++counts[colors[person]];
			}

			auto iter = std::max_element(std::begin(counts), std::end(counts));
			if (*iter > (end - begin + 1) / 2)
			{
				printf("yes %d\n", iter - std::begin(counts));
			}
			else
			{
				printf("no\n");
			}
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