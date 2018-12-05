#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <string.h>
using namespace std;
int set[100];
int length = 0;
int a[51][51];
int b[51][51];
int d[51][51];
class Edge {
public:
	int u;
	int v;
	int w;
	Edge(int from, int to, int weight);
	Edge();
};
Edge::Edge() {
	u = -1;
	v = -1;
	w = -1;
}
Edge::Edge(int from, int to, int weight) {
	u = from;
	v = to;
	w = weight;
}
int compareEdge(const void* a, const void* b) {
	Edge* e1 = (Edge*)a;
	Edge* e2 = (Edge*)b;
	return e1->w - e2->w;//sort in increasing order
}
int compareEdge1(const void* a, const void* b) {
	Edge* e1 = (Edge*)a;
	Edge* e2 = (Edge*)b;
	return e2->w - e1->w;//sort in decreasing order
}
Edge *old_edges;
Edge *new_edges;
Edge *edges;//might need this not sure.
int find(int element) {
	if (set[element] < 0)
		return element;
	return set[element] = find(set[element]);
}
void UnionSet(int r1, int r2) {
	set[r1] += set[r2];
	set[r2] = r1;
}
void Union(int root1, int root2) {
	if (set[root1] < set[root2]) {//root1 has more members
		UnionSet(root1, root2);
	}
	else {
		UnionSet(root2, root1);
	}

}

int main() {
	string input;
	int n;
	while (getline(cin,input)) {
		length = 0;
		if (input[0] == '0')
			break;
		stringstream s1(input);
		s1 >> n;
		int ctr1 = 0;
		int ctr2 = 0;
		old_edges = new Edge[(n*(n - 1)) / 2];//max number of edges
		new_edges = new Edge[(n*(n - 1)) / 2];
		memset(&set, -1, sizeof(int)*(n + 1));
		for (int i = 0; i < n; i++) {
			getline(cin, input);
			for (int j = 0; j < n; j++) {
				a[i][j] = input[j] - '0';
				if (j>i) {
					if (a[i][j] == 0 && i != j)
						ctr1++;
					else
						ctr2++;
				}
			}
		}
		old_edges = new Edge[ctr2];//max number of edges
		new_edges = new Edge[ctr1];
		int k = 0;
		for (int i = 0; i < n; i++) {
			getline(cin, input);
			stringstream s(input);
			for (int j = 0; j < n; j++) {
				int num;
				s >> num;
				if (j>i) {
					if (a[i][j] == 0) {
						Edge temp(i, j, num);
						new_edges[k++] = temp;
					}
				}
			}
		}
		k = 0;
		for (int i = 0; i < n; i++) {
			getline(cin, input);
			stringstream s(input);
			for (int j = 0; j < n; j++) {
				int num;
				s >> num;
				if (j>i) {
					if (a[i][j] == 1) {
						Edge temp(i, j, num);
						old_edges[k++] = temp;
					}
				}
			}
		}
		qsort(old_edges, ctr2, sizeof(Edge), compareEdge1);
		for (int i = 0; i < ctr2; i++) {
			int root1 = find(old_edges[i].u);
			int root2 = find(old_edges[i].v);
			if (root1 == root2) {
				length += old_edges[i].w;//destory this road
				continue;
			}
			Union(root1, root2);
		}
		qsort(new_edges, ctr1, sizeof(Edge), compareEdge);
		for (int i = 0; i < ctr1; i++) {
			int root1 = find(new_edges[i].u);
			int root2 = find(new_edges[i].v);
			if (root1 == root2)
				continue;
			Union(root1, root2);
			length += new_edges[i].w;//cost of building a new edge
		}
		cout << length << endl;
	}
	return 0;
}