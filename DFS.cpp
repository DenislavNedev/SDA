#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& graph, vector<bool>& visited, int s)
{
	visited[s] = true;
	vector<int>::iterator i;
	
		for (i = graph[s].begin(); i != graph[s].end(); i++)
		{
			if (!visited[*i])
			{
				DFS(graph, visited, *i);	
			}
		}
}