////This is called maximum closure program
//// Don't use edmond karp for progrms with a lot of edges
//// Use adjaceny list for this program
//#include <iostream>
//#include <string.h>
//#include <queue>
//#include <math.h>
//#include <limits.h>
//#include <vector>
//using namespace std;
//int ctr = -1;//used to count the number of nodes
//struct Edge {
//	int v;// TO v
//	int flow;
//	int capacity;
//	int reverse; //store index of reverse edge to quickly find it
//};
//vector<Edge> *edges;
//void addEdge(int u, int v, int c) {
//	Edge a{ v,0,c,edges[v].size()};//to vertex v with flow 0 and capacity c. reverse edge will be located at the index size(length) because we are adding the new edge.
//	Edge b{ u,0,0,edges[u].size()};
//	edges[u].push_back(a);
//	edges[v].push_back(b);
//}
//int weight[5002];
//int level[5002];
//long int profit;
//bool bfs(int source, int sink, int n) {// similar to edmond karp but we only mark the level. Try to find all possible flows for each level
//	memset(level, -1, sizeof(int)*n);
//	level[source] = 0;
//	ctr = -1;
//	profit = 0;
//	queue <int> q;
//	q.push(source);
//	while (!q.empty()) {
//		int u = q.front();
//		ctr++;
//		q.pop();
//		vector<Edge>::iterator it;
//		for (it = edges[u].begin(); it != edges[u].end(); it++) {
//			Edge &e = *it;
//			if ((e.capacity - e.flow) > 0 && level[e.v] == -1) {
//				level[e.v] = level[u] + 1;
//				q.push(e.v);
//				profit += weight[e.v];
//			}
//		}
//	}
//	if (level[sink] == -1)
//		return false;
//	else
//		return true;
//}
//int sendFlow(int u, int sink, int f, int start[]) {
//	if (u == sink)
//		return f;
//	for (; start[u] < edges[u].size();start[u]++) {
//		Edge &e = edges[u][start[u]];
//		if (level[e.v] == level[u] + 1 &&( e.capacity - e.flow)>0) {
//			int current_flow = min(f, e.capacity-e.flow);
//			int temp_flow = sendFlow(e.v, sink, current_flow,start);
//			if (temp_flow > 0) {
//				e.flow += temp_flow;
//				edges[e.v][e.reverse].flow -= temp_flow;
//				return temp_flow;
//			}
//		}
//	}
//	return 0;
//}
//int dinic(int source, int sink, int n) {
//	if (source == sink)
//		return -1;
//	long int max_flow = 0;
//	while (bfs(source, sink, n)) {
//		int *start = new int[n];
//		memset(start, 0, sizeof(int)*n);
//		while (int f = sendFlow(source, sink, INT_MAX, start)) {
//			max_flow += f;
//		}
//	}
//	return max_flow;
//}
//int main() {
//	int n, m;
//	while (cin >> n >> m) {
//		long int sum = 0;
//		edges = new vector<Edge>[n + 2];
//		weight[0] = 0;
//		weight[n + 1] = 0;
//		for (int i = 1; i <= n; i++) {
//			int w;
//			cin >> w;
//			weight[i] = w;
//
//			if (w > 0) {
//				addEdge(0, i, w);
//				sum += w;
//			}
//			else
//				addEdge(i, n + 1, -w);
//		}
//		for (int i = 0; i < m; i++) {
//			int u, v;
//			cin >> u >> v;
//			addEdge(u, v, INT_MAX);
//		}
//		dinic(0, (n + 1), (n + 2));
//		cout << ctr << " " << profit << endl;
//	}
//	return 0;
//}