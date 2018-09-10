//#include <iostream>
//#include <cstdlib>
//#include <limits.h>
//using namespace std;
//
//int main() {
//	int arr[10000];
//	int n;
//	while (cin >> n) {
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//		int max_profit = INT_MIN;
//		for (int i = 0; i < n - 1; i++) {
//			for (int j = i + 1; j < n; j++) {
//				max_profit = max_profit > (arr[j] - arr[i]) ?  max_profit : arr[j] - arr[i];
//			}
//		}
//		if (max_profit < 0)
//			cout << "QUIT" << endl;
//		else
//			cout << max_profit << endl;
//	}
//	return 0;
//}
//