#include <iostream>
#include <list>
#include <queue>
#include <cstring>
#define INF 0xfffffff;
using namespace std;
int set[101];
int find(int element) {
	if (set[element] < 0)

		return element;
	return set[element] = find(set[element]);
}
void UnionSet(int r1, int r2) {
	set[r1] += set[r2];
	set[r2] = r1;
}
void Union(int root1,int root2) {// calling this function only if find doesnt occur;
	if (set[root1] < set[root2]) {//root1 has more members
		UnionSet(root1, root2);
	}
	else {
		UnionSet(root2, root1);
	}
}
class Edge {
public:
	int u, v, w;
	Edge(int from,int to, int weight);
	Edge();
};
Edge::Edge() {
	u = v = w = -1;
}
Edge::Edge(int from, int to, int weight) {
	u = from;
	v = to;
	w = weight;
}
Edge * edges;
int compareEdge(const void*a, const void* b) {
	Edge *e1 = (Edge *)a;
	Edge *e2 = (Edge *)b;
	return e1->w - e2->w;
}
int length;
int *visited;
bool flag1 = true;
list<Edge> *MST;
void dfs(int from_index,int to_index, int weight) {
	if (from_index == to_index) {
		length = weight;
		flag1 = false;
		return;
	}
	visited[from_index] = true;
	for (list<Edge>::iterator it = MST[from_index].begin(); it != MST[from_index].end(); it++) {
		if (visited[it->v] == false && flag1) {
			dfs(it->v,to_index, weight > it->w ? weight : it->w);
		}
	}
}

int main() {
	int ctr = 1;
	int c, s, q;
	while (cin >> c >> s >> q) {
		length = 0;
		if (c == 0 && s ==0 && q == 0)
			return 0;
		edges = new Edge[s];
		flag1 = true;
		MST = new list<Edge>[c+1];
		visited = new int[c + 1];
		memset(set, -1, sizeof(int)*(c + 1));
		
		for (int i = 0; i < s; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			Edge e(u, v, w);
			edges[i] = e;
		}
		qsort(edges, s, sizeof(Edge), compareEdge);
		for (int i = 0; i < s; i++) {
			int u = edges[i].u;
			int v = edges[i].v;
			int root1 = find(u);
			int root2 = find(v);
			if (root1 == root2)
				continue;
			MST[u].push_back(edges[i]);
			Edge temp(v, u, edges[i].w);
			MST[v].push_back(temp);
			Union(root1, root2);
		}
		if(ctr==1)
			cout << "Case #" << ctr++ << endl;
		else
			cout << "\nCase #" << ctr++ << endl;
		for (int i = 0; i < q; i++) {
			int u, v;
			cin >> u >> v;
			if (find(u)!=find(v)) {
				cout << "no path" << endl;
				continue;
			}
			length = 0;
			memset(visited, false, sizeof(int)*(c + 1));
			flag1 = true;
			dfs(u, v, 0);
			cout << length <<endl;
		}
	}
	return 0;
}