//#include <iostream>
//#include <math.h>
//using namespace std;
//int arr[1000000] = { 0 };//if number is prime
//int arr1[1000000] = { 0 };//if number is circular prime
//void prime() {
//	for (int i = 2; i < 1000000; i++) {
//		if (arr[i] == 0) {
//			for (int j = 2 * i; j < 1000000; j=j+i) {
//				arr[j] = 1;
//			}
//		}
//	}
//}
//int main() {
//	prime();
//	for (int i = 100; i <= 1000000; i++) {
//		if (arr[i] == 1)
//			continue;
//		bool flag = true;
//		int num = i;
//		int num1 = i;
//		int digits = 1;
//		while (num /= 10) {
//			digits++;
//		}
//		for (int j = 1; j <= digits; j++) {
//			int d = (num1) % 10;//last digit
//			num1 /= 10;
//			num1 += (d * pow(10, digits - 1));
//			if (arr[num1] == 1) {
//				flag = false;
//				break;
//			}
//		}
//		if (flag) {
//			arr1[i] = 1;
//			for (int j = 1; j <= digits; j++) {
//				int d = (num1) % 10;//last digit
//				num1 /= 10;
//				num1 += (d * pow(10, digits - 1));
//				arr[num1] = 0;//don't check again
//			}
//		}
//	}
//	int n, m;
//	while (cin >> n) {
//		int ctr = 0;
//		if (n == -1)
//			return 0;
//		cin >> m;
//		for (int i = n; i <= m; i++) {
//			ctr += arr1[i];
//		}
//		if (ctr == 0) 
//			cout << "No Circular Primes." << endl;
//		else
//			cout << ctr <<" Circular Primes." << endl;
//	}
//	return 0;
//}