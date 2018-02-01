// https://www.acmicpc.net/problem/9536

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>


int main()
{
	std::string str;

	std::getline(std::cin, str);

	std::stringstream sstream;

	sstream.str(str);

	std::string temp;

	sstream >> temp;

	std::cout << temp << '\n';
	
	return 0;
}
