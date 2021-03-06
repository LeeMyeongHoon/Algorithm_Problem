//https://www.acmicpc.net/problem/2309

#include <iostream>
#include <vector>
#include <algorithm>

struct Soluter
{
	static const size_t ALL_STUDENT_COUNT = 9;
	static const size_t REAL_STUDENT_COUNT = 7;

	size_t heights[ALL_STUDENT_COUNT];
	std::vector<size_t> realStudentHeights;
	bool isFinish = false;

	void Input()
	{
		for (size_t i = 0; i < ALL_STUDENT_COUNT; i++)
		{
			std::cin >> heights[i];
		}

	}

	bool FindAnswer(size_t student, size_t sum)
	{
		if (realStudentHeights.size() == REAL_STUDENT_COUNT)
		{
			if (sum == 100)
			{
				return true;
			}
		}

		if (student >= ALL_STUDENT_COUNT || sum > 100)
		{
			return false;
		}

		realStudentHeights.push_back(heights[student]);
		
		if (FindAnswer(student + 1, sum + heights[student]))
		{
			return true;
		}
		realStudentHeights.pop_back();

		if (FindAnswer(student + 1, sum))
		{
			return true;
		}

		return false;
	}

	void Solve()
	{
		FindAnswer(0, 0);

		std::sort(std::begin(realStudentHeights), std::end(realStudentHeights));

		for (auto& realStudentHeight : realStudentHeights)
		{
			std::cout << realStudentHeight << '\n';
		}
	}


};

size_t main()
{
	Soluter soluter;

	soluter.Input();
	soluter.Solve();

	return 0;
}