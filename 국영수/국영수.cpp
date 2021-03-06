#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Student
{
	std::string name;
	int kor;
	int eng;
	int math;
};

struct Soluter
{
	int n;
	std::vector<Student> students;

	void Input()
	{
		std::cin >> n;
		students.assign(n, {});

		for (auto& stu : students)
		{
			std::cin >> stu.name >> stu.kor >> stu.eng >> stu.math;
		}
	}

	void Solve()
	{
		std::sort(std::begin(students), std::end(students),
			[](const Student& lhs, const Student& rhs)
		{
			if (lhs.kor != rhs.kor)
			{
				return lhs.kor > rhs.kor;
			}

			// 국어점수 같은 경우
			if (lhs.eng != rhs.eng)
			{
				return lhs.eng < rhs.eng;
			}

			// 영어점수 같은 경우
			if (lhs.math != rhs.math)
			{
				return	lhs.math > rhs.math;
			}

			return lhs.name < rhs.name;
		});

		for (auto& stu : students)
		{
			std::cout << stu.name << '\n';
		}
	}
};

int main()
{
	Soluter soluter;
	soluter.Input();
	soluter.Solve();

	return 0;
}