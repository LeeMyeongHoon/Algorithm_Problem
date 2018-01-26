#include <stdio.h>

int main(void)
{
	const __int128 m = 3329589384618324948;
	__int128 n = m * m;

	enum { base = 10, max_width = 39 };

	char a[max_width + 1] = { '\0' };
	char *p = a + max_width;
	for (; n != 0; n /= base) *--p = (char)('0' + n % base);

	printf("%s\n", p);
}