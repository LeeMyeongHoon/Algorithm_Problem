#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> arr{ 1,2,3,4,5,6 };

	auto range = std::equal_range(std::begin(arr), std::end(arr), 5);

	std::cout << range.second - range.first << '\n';

	return 0;
}