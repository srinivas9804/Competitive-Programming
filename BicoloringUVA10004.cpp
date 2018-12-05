#include <iostream>
#include <queue>
#include <list>
#include <cstring>
using namespace std;
class Edge {
public:
	int v;
	Edge(int b);
	Edge();
};
Edge::Edge() {
	v = -1;
}
Edge::Edge(int b) {
	v = b;
}
list<Edge>* edges;
int color[200];

int main() {
	int n, l;
	while (cin >> n) {
		memset(color, -1, sizeof(color));
		list<Edge>* edges = new list<Edge>[n];
		if (n == 0)
			return 0;
		cin >> l;
		for (int i = 0; i < l; i++) {
			int u, v;
			cin >> u >> v;
			Edge e(v);
			Edge e1(u);
			edges[u].push_back(e);
			edges[v].push_back(e1);
		}
		color[0] = 0;
		queue<int> q;
		q.push(0);
		bool flag = true;
		while (!q.empty() && flag) {
			int u = q.front();
			int color1 = color[u]==0?1:0;
			q.pop();
			list<Edge>::iterator it;
			for (it = edges[u].begin(); it != edges[u].end(); it++) {
				if (color[it->v] == -1) {
					q.push(it->v);
					color[it->v] = color1;
				}
				else {
					if (color[it->v] == color[u]) {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag)
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
	}
	return 0;
}