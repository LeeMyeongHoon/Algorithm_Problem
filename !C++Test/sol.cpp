#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <bitset>
#include <unordered_map>
#include <array>

int main()
{
	std::bitset<3> aaa;
	std::vector<bool> aa;

	std::unordered_map<std::bitset<3>, int> z;

	z[aaa] = 1;

	std::cout << z[aaa] << '\n';

	return 0;
}