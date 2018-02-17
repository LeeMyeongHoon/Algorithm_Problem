#ifdef 완전탐색_시간초과
#include <iostream>
#include <algorithm>
#include <vector>

enum Blank
{
	EMPTY = -1, VALID = 1, INVALID = 0
};

struct Soluter
{
	int endI, endJ;
	std::vector<std::vector<Blank>> data;

	void Input()
	{
		std::cin >> endJ >> endI;

		data.assign(endI, std::vector<Blank>(endJ));

		for (int i = 0; i < endI; i++)
		{
			for (int j = 0; j < endJ; j++)
			{
				std::cin >> (int&)data[i][j];
			}
		}
	}

	struct Update_ret
	{
		bool hasUpdate;
		bool isAllValid;
	};

	Update_ret Update()
	{
		std::vector<std::vector<bool>> isJustValidate(endI, std::vector<bool>(endJ, false));
		bool hasUpdate = false;
		bool isAllValid = true;

		for (int i = 0; i < endI; i++)
		{
			for (int j = 0; j < endJ; j++)
			{
				if (data[i][j] == INVALID)
				{
					isAllValid = false;
				}

				if (data[i][j] == VALID && !isJustValidate[i][j])
				{
					auto UpdateAdj = [&](int i, int j)
					{
						if (i < 0 || j < 0 || i == endI || j == endJ)
						{
							return;
						}
						if (data[i][j] == INVALID)
						{
							isAllValid = false;
							hasUpdate = true;
							data[i][j] = VALID;
							isJustValidate[i][j] = true;

						}
					};

					UpdateAdj(i + 1, j);
					UpdateAdj(i - 1, j);
					UpdateAdj(i, j + 1);
					UpdateAdj(i, j - 1);
				}
			}
		}

		return { hasUpdate,isAllValid };
	}

	void Solve()
	{
		int count = 0;

		do
		{
			auto ret = Update();
			if (ret.isAllValid)
			{
				break;
			}

			else
			{
				++count;
				if (ret.hasUpdate == false)
				{
					count = -1;
					break;
				}
			}

		} while (true);

		std::cout << count << '\n';
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}
#endif // 완전탐색_시간초과
