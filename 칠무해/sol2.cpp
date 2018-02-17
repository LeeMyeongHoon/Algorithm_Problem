#ifdef 메모리초과 ㄷㄷ
#include <algorithm>
#include <iomanip>
#include <vector>


int main()
{
	int count;
	scanf("%d", &count);

	std::vector<double> data(count);

	for (int i = 0; i < count; i++)
	{
		scanf("%lf", &data[i]);
	}

	std::sort(std::begin(data), std::end(data));

	printf("%.3lf\n%.3lf\n%.3lf\n%.3lf\n%.3lf\n%.3lf\n%.3lf",
		data[0],
		data[1],
		data[2],
		data[3],
		data[4],
		data[5],
		data[6]
	);


	return 0;
}

#endif // 메모리초과 ㄷㄷ
