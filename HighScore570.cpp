//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include <math.h>
//#include <limits.h>
//#include <algorithm>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	while (n--) {
//		string input;
//		cin >> input;
//		int ctr = 0;
//		bool flag = true;//if flag true increment otherwise decrement
//		int k = 0;
//		for (int i = 0; i < input.length(); i++) {
//			if (input[i] > 'M')
//				ctr += 26 - abs('A' - input[i]);
//			else
//				ctr += abs('A' - input[i]);
//		}
//		int forward = -1;
//		int back = 0;
//		int ctr1 = 0;
//		if (ctr == 0) {
//			cout << ctr << endl;
//			continue;
//		}
//		for (int i = 0; i < input.length(); i++) {
//			if (input[i] != 'A') {
//				ctr1++;
//				if (forward == -1) {
//					forward = i;
//					back = ((int)input.length()) - i;
//				}
//				else if (back == 0)
//					back = INT_MAX;
//				else {
//					back = min(back, forward + forward + ((int)input.length()) - i);
//					back = min(back, forward + ((int)input.length()) - i + ((int)input.length()) - i);
//					forward = i;
//
//				}
//			}
//		}
//		if (ctr1 == 1)
//			back = min(forward, ((int)input.length()) - forward);
//		back = min(back, forward);
//		ctr += back;
//		cout << ctr << endl;
//	}
//	return 0;
//}