// https://www.acmicpc.net/problem/2941

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

const char* croTwoChars[] = { "c=","c-","d-","lj","nj","s=","z=" };
const char* croThreeChar = "dz=";

int main()
{
	std::string str;
	std::cin >> str;

	int count = 0;
	for (int i = 0; i < str.size();)
	{
		// 두글자체크
		bool isCheck = false;
		if (i + 1 < str.size())
		{
			for (auto& croTwoChar : croTwoChars)
			{
				if (croTwoChar[0] == str[i] && croTwoChar[1] == str[i + 1])
				{
					count++;
					i += 2;
					isCheck = true;
					break;
				}
			}
		}

		// 세글자 체크
		if (!isCheck &&  i + 2 < str.size())
		{
			if (croThreeChar[0] == str[i] && croThreeChar[1] == str[i + 1] && croThreeChar[2] == str[i + 2])
			{
				count++;
				i += 3;
				isCheck = true;
			}
		}

		if (!isCheck)
		{
			i++;
			count++;
		}
	}

	std::cout << count << '\n';

	return 0;
}