#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

int vertexCount;
std::vector<std::vector<std::pair<int, int>>> adj;
const int INF = std::numeric_limits<int>::max();

std::vector<int> dijkstra2(int src)
{
	std::vector<int > dist(vertexCount, INF);
	std::vector<bool> visited(vertexCount, false);
	dist[src] = 0;
	while (true)
	{
		int closest = INF;
		int here;
		for (int i = 0; i < vertexCount; i++)
		{
			if (dist[i] < closest && !visited[i])
			{
				here = i;
				closest = dist[i];
			}
		}

		if (closest == INF)
		{
			break;
		}

		visited[here] = true;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int next = adj[here][i].second;
			if (visited[next])
			{
				continue;
			}
			int nextDist = dist[here] + adj[here][i].first;
			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
			}
		}
	}
	return dist;
}

