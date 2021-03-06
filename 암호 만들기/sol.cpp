// https://www.acmicpc.net/problem/1759

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool isConsonant(char ch)
{
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

struct Soluter
{
	int pwLength;
	int charCount;
	std::vector<char> data;
	std::vector<std::string> words;

	void Input()
	{
		std::cin >> pwLength >> charCount;

		data.assign(charCount, {});

		for (auto& ch : data)
		{
			std::cin >> ch;
		}
	}


	void SetPassword(std::string& password, int i)
	{
		if (password.length() == pwLength)
		{
			words.push_back(password);
			return;
		}

		if (i >= charCount)
		{
			return;
		}

		password.push_back(data[i]);
		SetPassword(password, i + 1);
		password.pop_back();

		SetPassword(password, i + 1);
	}

	void Solve()
	{
		std::sort(std::begin(data), std::end(data));

		std::string password;
		SetPassword(password, 0);

		for (auto& word : words)
		{
			int consonantCount = std::count_if(std::begin(word), std::end(word), isConsonant);
			int vowelCount = word.size() - consonantCount;

			if (consonantCount >= 1 && vowelCount >= 2)
			{
				std::cout << word << '\n';
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