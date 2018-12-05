#include <iostream>
#define INF 0xFFFFFFF
using namespace std;
int dist[101][101];
int num = 0;
int n, m;
/*for this program you only need to calculate the upper diagonal elements because the dist[i][j]==dist[j][i]*/
void floydwarshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if(dist[i][k]<INF)
			for (int j = i+1; j <= n; j++) {//only upper diagonal i+1
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					dist[j][i] = dist[i][j];//same distance as the other diagonal
				}
			}
		}
	}
}
int main() {
	int n1 = 100;
	while (cin >> n >> m) {
		for (int i = 1; i <= n1; i++) {
			for (int j = 1; j <= n1; j++) {
				if (i == j)
					dist[i][j] = 0;
				else
					dist[i][j] = INF;
			}
		}
		n1 = n;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			dist[u][v] = w;
			dist[v][u] = w;
		}
		floydwarshall();

		int sum = 0;
		int index = 0;
		for (int i = 1; i <= n; i++) {
			int s = 0;
			for(int j=1;j<=i;j++){
				s += dist[j][i];//for elements before the diagonal
			}
			for (int j = i + 1; j <= n; j++) {
				s += dist[i][j];// for elements after the diagonal
			}
			if (sum > s || sum == 0) {
				sum = s;
				index = i;
			}
		}
		cout << index << endl;
	}
	return 0;
}