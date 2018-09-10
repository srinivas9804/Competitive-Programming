//#include <iostream>
//using namespace std;
//int recur(int n) {
//	if (n == 0) {
//		return 2;
//	}
//	else
//		return 3 * recur(n - 1) + 2;//2 movements of the largest disk to C + you have to move the other n-1
//									  //disks from A to C, C to A and back to C.
//}
//int main() {
//	
//	int num = 0;
//	while (cin >> num) {
//		if (num == 0) {
//			cout << num << endl;
//			continue;
//		}
//		int val = 0;
//		val = recur(num-1);
//		cout << val << endl;
//	}
//	return 0;
//}