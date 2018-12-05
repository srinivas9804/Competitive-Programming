// for this program you have to find the minimum cut of all the edges created 
//from north(bottom left) to south(top right).
// This give the minimum cut, the minimum number of robots(Edge weights 1) the winger has to cross.
// ONLY ONE TACKLE EACH, SO EACH ROBOT MUST BE MODLED INTO A VERTEX WITH CAPACITY 1.
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <limits.h>
using namespace std;
inline bool bfs(int **graph, int source, int sink, int *parent,int numberOfNodes ) {// bfs to return path from source to sink
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
inline int edmondKarp(int **graph, int source, int sink,int numberOfNodes) {
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
	int l, w, n, d;
	int ctr = 1;
	pair <int,int> coord[102];//maximum number of vertices.
	while (cin >> l >> w >> n >> d) {
		if (l==0 &&w==0&&n==0&&d==0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			int x, y;
			cin >> x >> y;
			coord[i] = make_pair(x, y);
		}
		int **G = new int*[2*n + 2];
		for (int i = 0; i <= (2*n+1); i++) {
			G[i] = new int[2*n + 2];
			memset(G[i], 0, sizeof(int)*(2*n + 2));
		}
		for (int i = 1; i <= n; i++) {
			G[(i * 2) - 1][i * 2] = 1;
			if (coord[i].second <= d) {
				G[0][(i*2)-1] = 1;
			}
			if ((w - coord[i].second) <= d) {
				G[i*2][((2*n) + 1)] = 1;
			}
		}
		for (int i = 1; i <=  n; i++) {
			for (int j = 1 ; j <= n ; j++) {
				//if two circles intersect,(R0-R1)^2 <= (x0-x1)^2+(y0-y1)^2 <= (R0+R1)^2
				if (i == j)
					continue;
				if ((pow(coord[i].first - coord[j].first, 2) + pow(coord[i].second - coord[j].second, 2)) <= pow(2 * d, 2)) {
					G[i*2][j*2-1] = 1;
				}			
			}
		}
		int flow = edmondKarp(G, 0, (2*n + 1), (2*n + 2));
		cout <<"Case "<<ctr++<<": "<< flow << endl;
	}
	return 0;
}