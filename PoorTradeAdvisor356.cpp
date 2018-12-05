#include <iostream>
#include <list>
#include <cstdlib>
#include <math.h>
#include <string.h>
using namespace std;
int set[501];
int maximum = -1;
class Edge {
public:
	int u;
	int v;
	int w;
	Edge(int from, int to, int weight) {
		u = from;
		v = to;
		w = weight;
	}
};
int find(int element) {
	if (set[element] < 0)
		return element;
	return set[element] = find(set[element]);
}
void UnionSet(int r1, int r2) {
	set[r1] += set[r2];
	if (set[r1] < maximum)
		maximum = set[r1];
	set[r2] = r1;
}
void Union(int element1, int element2) {
	int root1 = find(element1);
	int root2 = find(element2);
	if (root1 == root2)
		return;
	if (set[root1] < set[root2]) {//root1 has more members
		UnionSet(root1, root2);
	}
	else {
		UnionSet(root2, root1);
	}

}
int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			break;
		list <Edge> edges;
		maximum = -1;
		memset(&set, -1, sizeof(int)*(n + 2));
		int largest_weight;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			Edge temp(u,v,w);
			edges.push_back(temp);
			if (i == 0)
				largest_weight = w;
			if (w > largest_weight)
				largest_weight = w;
		}
		list<Edge>::iterator it;
		for (it = edges.begin(); it != edges.end(); it++) {
			if (it->w == largest_weight) {
				Union(it->u, it->v);
			}
		}
		cout << abs(maximum) << endl;
	}
	return 0;
}
