//#include <iostream>
//#include <queue>
//#define INF 0x5FFFFFFF;
//using namespace std;
//class node {
//public:
//	int row;
//	int column;
//	int distance;
//	node(int, int, int);
//	bool operator<(const node& a)const {//min priority queue
//		return distance > a.distance;
//	}
//};
//node::node(int a, int b, int d) {
//	row = a;
//	column = b;
//	distance = d;
//}
//int arr[125][125];
//int dist[125][125];
//priority_queue <node> pq;
//int n = 0;
//void relax(int r1, int c1, int r2, int c2) {// relax from r1,c1 to r2,c2
//	if (dist[r2][c2] > dist[r1][c1] + arr[r2][c2]) {
//		dist[r2][c2] = dist[r1][c1] + arr[r2][c2];
//		node newNode(r2, c2, dist[r2][c2]);
//		pq.push(newNode);
//	}
//}
//
//void dijkstras() {
//	while (!pq.empty()) {
//		node u = pq.top();
//		if (u.row == u.column && u.row == n - 1)
//			return;
//		pq.pop();
//		if (u.row != 0) {
//			relax(u.row, u.column, (u.row - 1), u.column);
//		}
//		if (u.column != 0) {
//			relax(u.row, u.column, u.row , (u.column - 1));
//		}
//		if (u.row != n - 1) {
//			relax(u.row, u.column, (u.row + 1), u.column);
//		}
//		if (u.column != n-1) {
//			relax(u.row, u.column, u.row, (u.column + 1));
//		}
//	}
//}
//int main() {
//	int ctr = 1;
//	while (cin >> n) {
//		if (n == 0)
//			return 0;
//		pq = priority_queue<node>();
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cin >> arr[i][j];
//				dist[i][j] = INF;
//			}
//		}
//		dist[0][0] = arr[0][0];
//		node start(0, 0, dist[0][0]);
//		pq.push(start);
//		dijkstras();
//		cout << "Problem " << ctr++ << ": " << dist[n - 1][n - 1] << endl;
//	}
//	return 0;
//}