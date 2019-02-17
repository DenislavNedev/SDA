#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

void prim(vector<vector<long long>>& graph, vector<long long>& distance, vector<bool>& visited, int vertexes, int s) {

	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> Q;
	distance[s] = 0;
	Q.push({ 0,s });

	while (!Q.empty()) {
		int v = Q.top().second;
		Q.pop();

		if (!visited[v]) {

			visited[v] = true;
			for (int i = 0; i < vertexes; i++)
			{
				if (graph[v][i] != LLONG_MAX)
				{
					if (!visited[i] && graph[v][i] < distance[i])
					{
						distance[i] = graph[v][i];
						Q.push({ distance[i],i });
					}
				}
			}
		}
	}

}