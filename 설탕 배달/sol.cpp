#include <cstdio>
#include <set>

int main()
{
	int num;
	int count;
	scanf("%d", &count);

	std::set<int> data;

	for (int i = 0; i < count; i++)
	{
		scanf("%d", &num);
		data.insert(num);
	}

	int cmdCount;
	scanf("%d", &cmdCount);
	int* cmds = new int[cmdCount];
	for (int i = 0; i < cmdCount; i++)
	{
		scanf("%d", &num);
		printf("%d ", data.find(num) != std::end(data));
	}
	

	return 0;
}