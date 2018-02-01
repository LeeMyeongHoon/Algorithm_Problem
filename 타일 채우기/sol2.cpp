
#include <iostream>
#include <vector>
#include <algorithm>

constexpr int GetCount(int width)
{
	if (width == 0)
	{
		return 1;
	}

	int count = 0;
	int newWidth = width - 2;
	if (newWidth >= 0)
	{
		count += (3 * GetCount(newWidth));
	}

	newWidth -= 2;
	while (newWidth >= 0)
	{
		count += (2 * GetCount(newWidth));
		newWidth -= 2;
	}

	return count;
}

int main()
{
	constexpr int caches[31] =
	{
		GetCount(0),
		GetCount(1),
		GetCount(2),
		GetCount(3),
		GetCount(4),
		GetCount(5),
		GetCount(6),
		GetCount(7),
		GetCount(8),
		GetCount(9),
		GetCount(10),
		GetCount(11),
		GetCount(12),
		GetCount(13),
		GetCount(14),
		GetCount(15),
		GetCount(16),
		GetCount(17),
		GetCount(18),
		GetCount(19),
		GetCount(20),
		GetCount(21),
		GetCount(22),
		GetCount(23),
		GetCount(24),
		GetCount(25),
		GetCount(26),
		GetCount(27),
		GetCount(28),
		GetCount(29),
		GetCount(30)
	};

	int n;
	scanf("%d", &n);
	printf("%d", caches[n]);

	return 0;
}
