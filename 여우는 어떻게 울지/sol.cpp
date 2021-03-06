// https://www.acmicpc.net/problem/9536

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <climits>

struct Soluter
{
	std::set<std::string> otherSounds;
	std::stringstream soundStream;

	void Input()
	{
		std::string inputLine;
		std::getline(std::cin, inputLine);

		soundStream.str(inputLine);

		for (;;)
		{
			std::getline(std::cin, inputLine);

			std::stringstream inputStream(inputLine);
			std::string word;
			inputStream >> word;

			if (word == "what")
			{
				while (inputStream >> word) {}
				break;
			}
			inputStream.ignore();
			inputStream.ignore(INT_MAX, ' ');

			inputStream >> word;

			otherSounds.insert(word);
		}
	}

	void Solve()
	{
		std::string sound;
		while (soundStream >> sound)
		{
			if (otherSounds.find(sound) == std::end(otherSounds))
			{
				std::cout << sound << ' ';
			}
		}
		std::cout << '\n';
	}
};

int main()
{
	int count;
	std::cin >> count;
	std::cin.ignore();

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