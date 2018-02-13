//#define SOL_2
//#ifdef SOL_2
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <stack>
//
//struct Data
//{
//	Data(int i, int sum)
//		: i(i), sum(sum)
//	{}
//
//	int i, sum;
//};
//
//struct Soluter
//{
//	int size;
//	std::vector<int> nums;
//
//	void Input()
//	{
//		std::cin >> size;
//		nums.assign(size, 0);
//		for (auto& num : nums)
//		{
//			std::cin >> num;
//		}
//	}
//
//	void Solve()
//	{
//		std::stack<Data> s;
//		s.emplace(0, 0);
//		int maxSum = std::numeric_limits<int>::min();
//
//		while (s.empty() != true)
//		{
//			int i = s.top().i;
//			int sum = s.top().sum;
//			s.pop();
//
//			if (i == size)
//			{
//				if (maxSum < sum)
//				{
//					maxSum = sum;
//				}
//				continue;
//			}
//
//			if (nums[i] == 0)
//			{
//				s.emplace(i + 1, sum);
//			}
//
//			int newSum = sum;
//			if (nums[i] < 0)
//			{
//				newSum += nums[i];
//				i++;
//				while (i < size && nums[i] < 0)
//				{
//					i++;
//					newSum += nums[i];
//				}
//				s.emplace(i, newSum);
//				s.emplace(i, 0);
//				if (maxSum < sum)
//				{
//					maxSum = sum;
//				}
//			}
//
//			// ¾ç¼ö
//			else
//			{
//				newSum += nums[i];
//				i++;
//				while (i < size && nums[i] > 0)
//				{
//					newSum += nums[i];
//					i++;
//				}
//				s.emplace(i, newSum);
//			}
//		}
//
//		std::cout << maxSum << '\n';
//	}
//};
//
//int main()
//{
//	Soluter soluter;
//	soluter.Input();
//	soluter.Solve();
//	return 0;
//}
//#endif // SOL_2
