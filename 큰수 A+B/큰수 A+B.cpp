#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	std::string tmp1;
	std::string tmp2;

	std::cin >> tmp1 >> tmp2;

	std::string big(std::rbegin(tmp1), std::rend(tmp1));
	std::string small(std::rbegin(tmp2), std::rend(tmp2));

	if (big.size() < small.size())
	{
		std::swap(big, small);
	}


	int i;
	bool hasOver = false;
	std::string result;

	for (i = 0; i < small.size(); i++)
	{
		int n = big[i] - '0';
		int m = small[i] - '0';

		int c = n + m;
		if (hasOver)
		{
			c += 1;
			hasOver = false;
		}

		if (c >= 10)
		{
			c -= 10;
			hasOver = true;
		}

		result.push_back(c + '0');
	}

	while (i < big.size())
	{
		int c = big[i] - '0';
		if (hasOver)
		{
			c += 1;
			hasOver = false;
		}

		if (c >= 10)
		{
			c -= 10;
			hasOver = true;
		}


		result.push_back(c + '0');
		++i;
	}
	
	if (hasOver)
	{
		result.push_back('1');
	}

	for (auto iter = std::rbegin(result); iter < std::rend(result); ++iter)
	{
		std::cout << *iter;
	}


	return 0;
}