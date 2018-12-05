#include <iostream>
#include <list>
using namespace std;

int n, m;
int num_to_check = 0;
int dist[1001][1001] = { 0 };
void floydWarshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (dist[i][k] == num_to_check)
				for (int j = 1; j <= n; j++) {
					if ((dist[i][j] != num_to_check) && (dist[i][k] == num_to_check) && (dist[k][j] == num_to_check)) {
						/*
						actual relaxation step is
						if dist[i][j] > dist[i][k] + dist[k][j]
						dist[i][j] = dist[i][k] + dist[k][j]
						*/
						dist[i][j] = num_to_check;
					}
				}
		}
	}
}
int main() {

	while (cin >> n >> m) {
		num_to_check++;
		int ctr = 0;
		int u;
		int v;
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			dist[u][v] = num_to_check;

		}
		floydWarshall();
		for (int i = 1; i <= n; i++) {
			bool flag = true;
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				if (dist[i][j] == num_to_check || dist[j][i] == num_to_check) {

				}
				else {
					flag = false;
					break;
				}
			}
			if (flag == true)
				ctr++;
		}
		cout << ctr << endl;
	}
	return 0;
}