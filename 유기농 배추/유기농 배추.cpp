// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int width;
	int height;

	int count;
	bool data[50][50] = { false };

	void Input()
	{
		std::cin >> width >> height >> count;
		for (int i = 0; i < count; i++)
		{
			int x;
			int y;
			std::cin >> x >> y;
			data[y][x] = true;
		}
	}

	void Solve()
	{

	}
};

int main()
{

	return 0;
}