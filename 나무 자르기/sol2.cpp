//#include <cstdio>
//#include <algorithm>
//#include <map>
//#include <functional>
//
//struct Soluter
//{
//	int treeCount;
//	size_t keyLength;
//
//	std::map<size_t, size_t, std::greater<>> data;
//
//
//	void Input()
//	{
//		scanf("%u %u", &treeCount, &keyLength);
//
//		for (int i = 0; i < treeCount; i++)
//		{
//			size_t length;
//			scanf("%u", &length);
//			++data[length];
//		}
//	}
//
//	void Solve()
//	{
//		auto iter = std::begin(data);
//		size_t sum = 0;
//		int upperCount = 0;
//		auto lastIter = --std::end(data);
//		while (iter != lastIter)
//		{
//			size_t curLength = iter->first;
//			upperCount += iter->second;
//
//			++iter;
//
//			sum += (curLength - iter->first) * upperCount;
//			if (sum >= keyLength)
//			{
//				break;
//			}
//		}
//
//		size_t cut;
//		if (iter == --std::end(data))
//		{
//			upperCount += iter->second;
//
//			sum += (iter->first * upperCount);
//
//			cut = std::begin(data)->first;
//		}
//
//		else
//		{
//			cut = std::begin(data)->first - iter->first;
//		}
//
//		cut -= (sum - keyLength) / upperCount;
//
//		printf("%u", std::begin(data)->first - cut);
//	}
//};
//
//
//int main()
//{
//	Soluter soluter;
//	soluter.Input();
//	soluter.Solve();
//
//	return 0;
//}