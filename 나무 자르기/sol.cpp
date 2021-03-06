// https://www.acmicpc.net/problem/2805
#ifdef SOL_1
#include <cstdio>
#include <vector>
#include <map>
#include <functional>

struct Soluter
{
	int treeCount;
	size_t keyLength;

	std::map<size_t, size_t, std::greater<>> data;


	void Input()
	{
		scanf("%u %u", &treeCount, &keyLength);

		for (int i = 0; i < treeCount; i++)
		{
			size_t length;
			scanf("%u", &length);
			++data[length];
		}
	}

	void Solve()
	{
		auto iter = std::begin(data);
		size_t sum = 0;
		int upperCount = 0;
		while (iter != --std::end(data))
		{
			size_t curLength = iter->first;
			upperCount += iter->second;

			++iter;

			size_t nextLength = iter->first;
			sum += (curLength - nextLength) * upperCount;
			if (sum >= keyLength)
			{
				break;
			}
		}

		size_t cut;
		if (iter == --std::end(data))
		{
			size_t curLength = iter->first;
			upperCount += iter->second;

			sum += (curLength * upperCount);

			cut = std::begin(data)->first;
		}

		else
		{
			cut = std::begin(data)->first - iter->first;
		}

		cut -= (sum - keyLength) / upperCount;

		printf("%u\n", std::begin(data)->first - cut);
	}
};


int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}
#endif // SOL_1
