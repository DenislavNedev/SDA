#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void bellman_ford(vector<vector<long long>>& graph, vector<long long>& distance, int vertexes, int s)
{
	distance[s] = 0;
	for (int i = 0; i < vertexes - 1; i++)
	{
		for (int j = 0; j < vertexes; j++)
		{
			for (int k = 0; k < vertexes; k++)
			{
				if (graph[j][k] != LLONG_MAX)
				{
					if (distance[j] + graph[j][k] < distance[k])
					{
						distance[k] = distance[j] + graph[j][k];
					}
				}
			}
		}
	}
}