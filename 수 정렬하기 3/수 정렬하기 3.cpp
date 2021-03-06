// https://www.acmicpc.net/problem/10989

#include <cstdio>
#include <algorithm>

int main()
{
	int counts[10001] = { 0 };

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		counts[num]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int cnt = 0; cnt < counts[i]; cnt++)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}