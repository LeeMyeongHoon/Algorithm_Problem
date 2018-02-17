//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//struct Soluter
//{
//	int endJ;
//	std::vector<int> data[2];
//	std::vector<int> dp[2];
//
//
//	void Input()
//	{
//		scanf("%d", &endJ);
//		data[0].assign(endJ, {});
//		data[1].assign(endJ, {});
//
//		for (int i = 0; i < 2; i++)
//		{
//			for (int j = 0; j < endJ; j++)
//			{
//				scanf("%d", &data[i][j]);
//			}
//		}
//	}
//
//	void Solve()
//	{
//		for (auto& dpData : dp)
//		{
//			dpData.assign(endJ, {});
//		}
//
//		dp[0][0] = data[0][0];
//		dp[0][1] = data[0][1];
//
//		dp[0][1] 
//	}
//};
//
//int main()
//{
//	int count;
//	std::cin >> count;
//
//	std::vector<Soluter> soluters(count);
//
//	for (auto& soluter : soluters)
//	{
//		soluter.Input();
//	}
//
//	for (auto& soluter : soluters)
//	{
//		soluter.Solve();
//	}
//
//	return 0;
//}
