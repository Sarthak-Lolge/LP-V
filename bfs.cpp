#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void bfs(vector<vector<int>>& graph, int start, int V){
	vector<bool> visited(V, false);
	queue<int> q;

	visited[start] = true;
	q.push(start);

	while(!q.empty()){
		int node = q.front();
		q.pop();
		cout<<node<<" ";

		for(int neighbor : graph[node]){
			if(!visited[neighbor]){
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
}

int main(){
	int V = 5;
	vector<vector<int>> graph(V);
	graph[0] = {1,2};
	graph[1] = {0,3,4};
	graph[2] = {0};
	graph[3] = {1};
	graph[4] = {1};
	
	bfs(graph, 0, V);
	return 0;
}