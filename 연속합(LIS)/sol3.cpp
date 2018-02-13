//// 시간초과;;;
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
//	int maxSum = std::numeric_limits<int>::min();
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
//	void SetMax(int i, int sum)
//	{
//		if (i == size)
//		{
//			if (maxSum < sum)
//			{
//				maxSum = sum;
//			}
//			return;
//		}
//
//
//		int newSum = sum;
//
//		// 음수
//		if (nums[i] < 0)
//		{
//			if (maxSum < sum)
//			{
//				maxSum = sum;
//			}
//
//			do
//			{
//				newSum += nums[i];
//				i++;
//
//			} while (i < size && nums[i] <= 0);
//
//			SetMax(i, 0);
//			SetMax(i, newSum);
//		}
//
//		// 양수
//		else
//		{
//			do
//			{
//				newSum += nums[i];
//				i++;
//
//			} while (i < size && nums[i] >= 0);
//
//			SetMax(i, newSum);
//		}
//	}
//
//	void Solve()
//	{
//		SetMax(0, 0);
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