///*If you don't use the flow per se, but use the Ford-Fulkerson algorithm (or some version, like Edmonds-Karp), 
//you can get both the max-flow and the min-cut directly as a result. When looking for augmenting paths, you do a traversal, 
//in which you use some form of queue of as-yet-unvisited nodes (in the Edmonds-Karp version, you use BFS, which means a FIFO queue). 
//In the last iteration, you can't reach t from s (this is the termination criterion, after all). 
//At this point, the set of nodes you reached forms the s-part of the cut, while the nodes you didn't reach form the t-part*/.

//This problem is to find the min cut between s and t so that the routines can be solved as easily as possible
//S is core 1 and t is core 2
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
			residualGraph[u][i] -= path_flow;
			residualGraph[i][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		int **G = new int*[n+2];//source and sink
		G[0] = new int[n + 2];
		memset(G[0], 0, sizeof(int)*(n + 2));
		G[n + 1] = new int[n + 2];
		memset(G[n+1], 0, sizeof(int)*(n + 2));
		for (int i = 1; i <= n ; i++) {
			G[i] = new int[n + 2];
			memset(G[i], 0, sizeof(int)*(n + 2));
			cin >> G[0][i] >> G[i][n + 1];
		}
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			G[v][u] = w;
			G[u][v] = w;
		}
		int flow = edmondKarp(G, 0, (n + 1), n + 2);
		cout << flow << endl;
	}
	return 0;
}