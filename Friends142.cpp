#include <iostream>
#include <list>
#include <math.h>
#include <string.h>
using namespace std;
int set[30001];
int maximum = 0;
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
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		int n, m;
		cin >> n >> m;
		maximum = 0;
		memset(&set, -1, sizeof(int)*(n + 1));
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			Union(u, v);
		}
		cout << abs(maximum) << endl;
	}
	
	return 0;
}