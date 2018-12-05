#include <iostream>
#include <list>
#include <cstdlib>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;
int set[201];
class Edge {
public:
	int u;
	int v;
	double w;
	Edge(int from, int to, double weight);
	Edge();
};
Edge::Edge() {
	u = -1;
	v = -1;
	w = -1;
}
Edge::Edge(int from, int to, double weight) {
	u = from;
	v = to;
	w = weight;
}
Edge* edges;
int compareEdge(const void* a, const void* b) {
	Edge* e1 = (Edge*)a;
	Edge* e2 = (Edge*)b;
	if (e1->w > e2->w)
		return 1;
	else if (e2->w > e1->w)
		return -1;
	else
		return 0;
}
int find(int element) {
	if (set[element] < 0)
		return element;
	return set[element] = find(set[element]);
}
void UnionSet(int r1, int r2) {
	set[r1] += set[r2];
	set[r2] = r1;
}
void Union(int root1,int root2) {// calling this function only if find doesnt occu;

	if (set[root1] < set[root2]) {//root1 has more members
		UnionSet(root1, root2);
	}
	else {
		UnionSet(root2, root1);
	}

}
pair <int,int> stone[201];
double length = 0.0;
list<Edge>* MST;
int *visited;
bool flag1 = true;//
void dfs(int index, double l) {
	list<Edge>::iterator it;
	if (index == 2) {
		length = l;
		flag1 = false;
		return;
	}
	visited[index] = true;
	for (it = MST[index].begin(); it != MST[index].end(); it++) {
		if (visited[it->v] == false  &&flag1) {
			double weight=l;
			if (it->w > l)
				weight = it->w;
			dfs(it->v, weight);
		}
	}
}
int main() {
	int n;
	int program_counter = 1;
	while (cin >>  n) {
		if (n == 0)
			break;
		length = 0.0;
		flag1 = true;
		MST = new list<Edge>[n + 1];	
		visited = new int[n + 1];
		edges = new Edge[(n*(n - 1)) / 2 +1];
		memset(&set, -1, sizeof(int)*(n + 1));
		memset(visited, false, sizeof(int)*(n + 1));
		for (int i = 1; i <= n; i++) {
			int x, y;
			cin >> x >> y;
			stone[i] = make_pair(x, y);
		}
		int k = 0;
		for (int i = 1; i <= n; i++) {
			double dist;
			for (int j = i + 1; j <= n; j++) {
				 dist= sqrt(pow(stone[j].first - stone[i].first,2)+ pow(stone[j].second - stone[i].second, 2));
				 Edge temp(i, j, dist);
				 edges[k++] = temp;
			}
		}
		int ctr = 0;
		qsort(edges, k, sizeof(Edge), compareEdge);
		for (int i = 0; i < k; i++) {
			int u = edges[i].u;
			int v = edges[i].v;
			double w = edges[i].w;
			int root1 = find(u);
			int root2 = find(v);
			if (root1 == root2)
				continue;
			ctr++;
			MST[u].push_back(edges[i]);
			Edge temp(v, u, w);
			MST[v].push_back(temp);
			Union(root1, root2);
			if(ctr==n-1)
				break;
		}	
		list<Edge>::iterator it;
		dfs(1, 0);
		cout << "Scenario #" << program_counter++ << endl;
		cout << "Frog Distance = " << fixed << setprecision(3) << length << endl << endl;
	}
	return 0;
}