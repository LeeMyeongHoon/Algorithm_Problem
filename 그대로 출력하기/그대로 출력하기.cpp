#include <iostream>
#include <vector>
#include <string>
#include <iterator>

int main()
{
	std::vector<std::string> strings;
	std::string str;
	while (std::getline(std::cin, str))
	{
		strings.push_back(std::move(str));
	}

	for (auto& string : strings)
	{
		std::cout << string << '\n';
	}

	return 0;
}