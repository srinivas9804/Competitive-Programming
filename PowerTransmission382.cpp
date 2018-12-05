/*If you don't use the flow per se, but use the Ford-Fulkerson algorithm (or some version, like Edmonds-Karp), 
you can get both the max-flow and the min-cut directly as a result. When looking for augmenting paths, you do a traversal, 
in which you use some form of queue of as-yet-unvisited nodes (in the Edmonds-Karp version, you use BFS, which means a FIFO queue). 
In the last iteration, you can't reach t from s (this is the termination criterion, after all). 
At this point, the set of nodes you reached forms the s-part of the cut, while the nodes you didn't reach form the t-part*/

#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <limits.h>
using namespace std;
bool bfs(int **graph, int source, int sink, int *parent,int numberOfNodes ) {// bfs to return path from source to sink
	bool *visited = new bool[numberOfNodes];
	memset(visited, 0, sizeof(bool)*numberOfNodes);
	queue <int>q;
	q.push(source);
	visited[source] = true;
	parent[source] = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 0; v < numberOfNodes; v++) {
			if (visited[v] == false && graph[u][v] > 0) {
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}
	return (visited[sink]);
}
int edmondKarp(int **graph, int source, int sink,int numberOfNodes) {
	int **residualGraph = new int*[numberOfNodes];//residual capacity of an edge
	for (int i = 0; i < numberOfNodes; i++) {
		residualGraph[i] = new int[numberOfNodes];
	}
	for (int i = 0; i < numberOfNodes; i++) {
		for (int j = 0; j < numberOfNodes; j++) {
			residualGraph[i][j] = graph[i][j];
		}
	}
	int *parent=new int[numberOfNodes];
	int max_flow = 0;
	while (bfs(residualGraph, source, sink, parent, numberOfNodes)) {
		int path_flow = INT_MAX;
		for (int i = sink; i != source; i = parent[i]) {
			int u = parent[i];
			path_flow = min(path_flow, residualGraph[u][i]);
		}
		for (int i = sink; i != source; i = parent[i]) {
			int u = parent[i];
			if (u != source && i != sink) {// This condition is used because the input from source and output to sink is Infinite. 
//Remove this for normal Edmonds Karp
				residualGraph[u][i] -= path_flow;
				residualGraph[i][u] += path_flow;
			}
		}
		max_flow += path_flow;
	}
	return max_flow;
}
int main() {
	int n;
	while (cin >> n) {
		int **G = new int*[(n * 2)+2];//+2 for source and sink
		for (int i = 0; i < (n * 2 + 2); i++) {
			G[i] = new int[(n * 2) + 2];
			memset(G[i], 0, sizeof(int)*((n * 2) + 2));
		}
		for (int i = 1; i <= n; i++) {
			int w;
			int x = (i * 2) - 1;
			cin >> w;
			G[x][x+1] = w;
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			G[(u*2)][(v*2)-1] = w;
		}
		int b, d;
		cin >> b >> d;
		for (int i = 0; i < b; i++) {
			int v;
			cin >> v;
			G[0][(v*2)-1] = INT_MAX;
		}
		for (int i = 0; i < d; i++) {
			int u;
			cin >> u;
			G[(u*2)][(n * 2) + 1]= INT_MAX;
		}
		int max_flow = edmondKarp(G, 0, (n * 2 + 1), (n * 2 + 2));
		cout << max_flow << endl;
	}
	return 0;
}