//#include <iostream>
//using namespace std;
//
//int main() {
//	int k = 0;//max sections
//	int a = 0;//no. of nuts
//	int b = 0;//no. of divisors
//	int v = 0;// max number of nuts per section
//	while (cin >> k >> a >> b >> v) {
//		int ctr = 0;
//		while (a > 0) {
//			int nuts = 0;
//			if (b >= k - 1) {// max capacity
//				nuts = k * v;
//				b = b - (k - 1);
//			}
//			else {
//				nuts = (b + 1)*v;
//				b = 0;
//			}
//			a = a - nuts;
//			ctr++;
//		}
//		cout << ctr<<endl;
//	}
//	return 0;
//}