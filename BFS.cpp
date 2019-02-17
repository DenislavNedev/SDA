#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>& graph, vector<bool>& visited,vector<int>& distance, int s)
{
	visited[s] = true;
	queue<int> q;
	q.push(s);

	vector<int>::iterator i;

	while (!q.empty())
	{
		int cV = q.front();
		q.pop();
		
		for (i = graph[cV].begin(); i != graph[cV].end(); i++)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				distance[*i] += distance[cV] + 6;
				q.push(*i);
			}
		}
	}
}
