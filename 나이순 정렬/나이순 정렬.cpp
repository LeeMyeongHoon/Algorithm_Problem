// https://www.acmicpc.net/problem/10814

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>	

struct Data
{
	Data() = default;
	Data(int age, std::string name) : age(age), name(name) {}

	int age;
	std::string name;
};

int main()
{
	int count;
	std::cin >> count;

	std::vector<Data> list(count);

	for (auto& data : list)
	{
		std::cin >> data.age >> data.name;	
	}

	std::stable_sort(std::begin(list), std::end(list), [](Data left, Data right) { return left.age < right.age; });

	for (auto& data : list)
	{
		std::cout << data.age << ' ' << data.name << '\n';
	}

	return 0;
}