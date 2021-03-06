// https://www.acmicpc.net/problem/1546

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

int main()
{
	int count;
	std::cin >> count;

	std::vector<double> scores(count);

	for (auto& score : scores)
	{
		std::cin >> score;
	}

	auto max = *std::max_element(std::begin(scores), std::end(scores));

	for (auto& score : scores)
	{
		score = score / max * 100;
	}

	double sum = std::accumulate(std::begin(scores), std::end(scores), 0.0);

	std::cout << sum / count << '\n';

	return 0;
}