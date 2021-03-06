#include <iostream>
#include <algorithm>
#include <vector>

struct Soluter
{
	int count;
	std::vector<long long> A;
	std::vector<long long> B;
	std::vector<long long> C;
	std::vector<long long> D;

	void Input()
	{
		scanf("%d", &count);

		A.assign(count, {});
		B.assign(count, {});
		C.assign(count, {});
		D.assign(count, {});

		for (int i = 0; i < count; i++)
		{
			std::cin >> A[i] >> B[i] >> C[i] >> D[i];
		}
	}

	void Solve()
	{
		std::vector<long long> data1;
		data1.reserve(count*count);
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				data1.push_back(A[i] + B[j]);
			}
		}

		std::vector<long long> data2;
		data2.reserve(count*count);
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				data2.push_back(C[i] + D[j]);
			}
		}
		std::sort(std::begin(data2), std::end(data2));


		long long result = 0;
		for (auto& x : data1)
		{
			auto range = std::equal_range(std::begin(data2), std::end(data2), -x);
			result += (range.second - range.first);
		}

		std::cout << result << '\n';
	}

};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}