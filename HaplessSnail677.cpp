//#include <iostream>
//#include <math.h>
//using namespace std;
//
//int main() {
//	int h, u, d, f;
//	while (cin >> h >> u >> d >> f) {
//		int ctr = 0;
//		long double sum = 0.0;
//		long double perc = f / 100.0;
//		while (2 > 1) {
//			long double val = (u * pow(perc, ctr));
//			sum += val;
//			if (sum >= h) {
//				cout << "succeeded on day " << ctr + 1 << endl;
//				break;
//			}
//			val -= d;
//			if (val < 0) {
//				cout << "failed on day " << ctr + 2 << endl;
//				break;
//			}
//			sum -= d;
//			ctr++;
//		}
//	}
//	return 0;
//}