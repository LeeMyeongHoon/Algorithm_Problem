//https://www.acmicpc.net/problem/11723

#include <cstdio>

constexpr int bitOn[21]
=
{
	0,
	1 << 1,
	1 << 2,
	1 << 3,
	1 << 4,
	1 << 5,
	1 << 6,
	1 << 7,
	1 << 8,
	1 << 9,
	1 << 10,
	1 << 11,
	1 << 12,
	1 << 13,
	1 << 14,
	1 << 15,
	1 << 16,
	1 << 17,
	1 << 18,
	1 << 19,
	1 << 20
};

constexpr int bitOff[21]
=
{
	0,
	~(1 << 1),
	~(1 << 2),
	~(1 << 3),
	~(1 << 4),
	~(1 << 5),
	~(1 << 6),
	~(1 << 7),
	~(1 << 8),
	~(1 << 9),
	~(1 << 10),
	~(1 << 11),
	~(1 << 12),
	~(1 << 13),
	~(1 << 14),
	~(1 << 15),
	~(1 << 16),
	~(1 << 17),
	~(1 << 18),
	~(1 << 19),
	~(1 << 20)
};

inline void Solve()
{
	int cmdCount;
	int bit = 0;
	scanf("%d", &cmdCount);

	for (int cnt = 0; cnt < cmdCount; cnt++)
	{
		char str[7];
		scanf("%s", str);

		if (*str == 'a')
		{
			// all
			if (str[1] == 'l')
			{
				for (int x = 1; x <= 20; x++)
				{
					bit = 0b111111111111111111110;
				}
			}
			else // add
			{
				int x;
				scanf("%d", &x);
				bit |= bitOn[x];
			}
		}

		// empty
		else if (str[0] == 'e')
		{
			for (int x = 1; x <= 20; x++)
			{
				bit = 0;
			}
		}

		else
		{
			int x;
			scanf("%d", &x);

			if (str[0] == 'r')
			{
				bit &= bitOff[x];
			}

			else if (str[0] == 'c')
			{
				printf("%d\n", (bool)(bit & bitOn[x]));
			}

			else // (str[0] == 't')
			{
				bit ^= bitOn[x];
			}
		}
	}
}

int main()
{
	Solve();

	return 0;
}