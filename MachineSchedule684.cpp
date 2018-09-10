////This is a minimum vertex cover program. Minimum vertex cover is the same as maximum bipartite matching.
//#include <iostream>
//#include <string.h>
//#include <queue>
//#include <math.h>
//#include <limits.h>
//using namespace std;
//inline bool bfs(int **graph, int source, int sink, int *parent,int numberOfNodes ) {// bfs to return path from source to sink
//	bool *visited = new bool[numberOfNodes];
//	memset(visited, 0, sizeof(bool)*numberOfNodes);
//	queue <int>q;
//	q.push(source);
//	visited[source] = true;
//	parent[source] = -1;
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		for (int v = 0; v < numberOfNodes; v++) {
//			if (visited[v] == false && graph[u][v] > 0) {
//				q.push(v);
//				parent[v] = u;
//				visited[v] = true;
//			}
//		}
//	}
//	return (visited[sink]);
//}
//inline int edmondKarp(int **graph, int source, int sink,int numberOfNodes) {
//	int **residualGraph = new int*[numberOfNodes];//residual capacity of an edge
//	for (int i = 0; i < numberOfNodes; i++) {
//		residualGraph[i] = new int[numberOfNodes];
//	}
//	for (int i = 0; i < numberOfNodes; i++) {
//		for (int j = 0; j < numberOfNodes; j++) {
//			residualGraph[i][j] = graph[i][j];
//		}
//	}
//	int *parent=new int[numberOfNodes];
//	int max_flow = 0;
//	while (bfs(residualGraph, source, sink, parent, numberOfNodes)) {
//		int path_flow = INT_MAX;
//		for (int i = sink; i != source; i = parent[i]) {
//			int u = parent[i];
//			path_flow = min(path_flow, residualGraph[u][i]);
//		}
//		for (int i = sink; i != source; i = parent[i]) {
//			int u = parent[i];
//			residualGraph[u][i] -= path_flow;
//			residualGraph[i][u] += path_flow;
//		}
//		max_flow += path_flow;
//	}
//	return max_flow;
//}
//int main() {
//	int n, m, k;
//	while (cin >> n >> m >> k) {
//		//n+m is source and n+m+1 is sink
//		int ctr = 0;
//		int ctr1 = 0;
//		int ctr2 = 0;
//		int **G = new int*[(n + m) + 2];
//		int size = n + m + 2;
//		for (int i = 0; i < size; i++) {
//			G[i] = new int[size];
//			memset(G[i], 0, sizeof(int)*size);
//		}
//		for (int i = 0; i < k; i++) {
//			int u, v;
//			cin >> u >> v;
//			if (u == 0 || v == 0)
//				continue;
//			G[u][v+n] = 1;
//			G[n + m ][u] = 1;
//			G[v+n][n + m + 1]=1;
//		}
//		int flow = edmondKarp(G, n + m, n + m + 1, size);
//		cout << flow << endl;
//	}
//	return 0;
//}