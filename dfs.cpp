#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<bool> visited){
	visited[node] = true;
	cout<<node<<" ";
	for(int neighbor : graph[node]){
		if(!visited[neighbor])
			dfs(graph, neighbor, visited);
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
	
	vector<bool> visited(V, false);
	dfs(graph, 0, visited);

	return 0;

}