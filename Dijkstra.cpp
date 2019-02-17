#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
using namespace std;


void dijkstra(vector<vector<int>>& graph, vector<long long>& distance, int vertxes, int s)
{
	priority_queue< pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
	distance[s] = 0;
	q.push({ 0,s });

	while (!q.empty())
	{
		int v = q.top().second;
		q.pop();

		for (int i = 0; i < vertxes; i++)
		{
			if (graph[v][i] != -1)
			{
				if (distance[v] + graph[v][i] < distance[i] || distance[i] == -1)
				{
					distance[i] = distance[v] + graph[v][i];
					q.push({ distance[i],i });
				}
			}
		}
	}
}