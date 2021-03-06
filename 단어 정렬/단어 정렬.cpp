// https://www.acmicpc.net/problem/1181

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	int count;
	std::cin >> count;

	std::vector<std::string> words(count);

	for (auto& word : words)
	{
		std::cin >> word;
	}

	std::sort(std::begin(words), std::end(words),
		[](std::string lhs, std::string rhs)
	{
		if (lhs.size() < rhs.size())
		{
			return true;
		}
		else if (lhs.size() > rhs.size())
		{
			return false;
		}
		else
		{
			return lhs < rhs;
		}
	});

	words.erase(std::unique(std::begin(words), std::end(words)), std::end(words));

	for (auto& word : words)
	{
		std::cout << word << '\n';
	}

	return 0;
}