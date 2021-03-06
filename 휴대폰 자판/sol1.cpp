#ifdef SOL1_시간초과
// https://www.acmicpc.net/problem/5670

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <memory>

struct Soluter
{
	int wordCount;
	std::vector<std::string> words;

	bool Input()
	{
		if (!(std::cin >> wordCount))
		{
			return false;
		}
		words.assign(wordCount, {});
		for (auto& word : words)
		{
			std::cin >> word;
		}
		return true;
	}

	void Solve()
	{
		int sum = 0;
		std::vector<int> initCharSimilar['z' + 1];

		for (int i = 0; i < wordCount; i++)
		{
			initCharSimilar[words[i][0]].push_back(i);
		}

		for (int key = 0; key < wordCount; key++)
		{
			auto oldSimilar = std::make_unique<std::vector<int>>(initCharSimilar[words[key][0]]);

			if (oldSimilar->empty())
			{
				sum += 1;
				continue;
			}

			int count = 1;
			for (int ch = 1; ch < words[key].size(); ch++)
			{
				auto newSimilar = std::make_unique<std::vector<int>>();
				for (auto other : *oldSimilar)
				{
					if (ch < words[other].size() && words[key][ch] == words[other][ch])
					{
						newSimilar->push_back(other);
					}
				}


				if (oldSimilar->size() != newSimilar->size())
				{
					count++;
				}

				if (newSimilar->empty())
				{
					break;
				}

				oldSimilar = std::move(newSimilar);
			}

			sum += (count);
		}

		std::cout << std::fixed << std::setprecision(2) << (long double)sum / wordCount << '\n';
	}
};

int main()
{
	for (;;)
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
#endif // SOL1_시간초과
