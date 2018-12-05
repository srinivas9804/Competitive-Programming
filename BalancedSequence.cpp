#include <iostream>
#include <cstdlib>
using namespace std;

int compare(const void *a, const void *b) {
	pair<int, int> *p1 = (pair<int, int>*)a;
	pair<int, int> *p2 = (pair<int, int>*)b;
	if (p1->first - p2->first > 0) {
		return 1;
	}
	else if (p1->first - p2->first < 0) {
		return -1;
	}
	else {
		return p1->second - p2->second;
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int *arr = new int[n];
		memset(arr, 1, sizeof(int)*n);
		pair<int, int> *limits = new pair<int, int>[n];
		for (int i = 0; i < m; i++) {
			int l, r;
			cin >> l >> r;
			limits[i] = make_pair(l, r);
		}
		qsort(limits, sizeof(pair<int, int>), m, compare);
		for (int i = 0; i < m; i++) {
			int l = limits[i].first;
			int r = limits[i].second;
			if
			for (int j = l; j <= r; j++) {

			}
		}
	}
	return 0;
}