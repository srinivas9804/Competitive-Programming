//#include <iostream>
//#include <math.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	while (cin >> n >> m) {
//		int *d = new int[n+1];
//		fill(d,d+n+1, 0);
//		d[0] = 1;
//		for (int i = 0; pow(m, i) <= n; i++) {
//			int val = pow(m, i);
//			for (int j = 1; j<=n; j++) {
//				if (val <= j)
//					d[j] = (d[j] + d[j - (val)])% 1000000007;
//			}
//		}
//		cout << d[n]<< endl;	
//		delete d;
//	}
//	return 0;
//}