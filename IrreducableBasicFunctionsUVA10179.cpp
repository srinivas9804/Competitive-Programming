//#include <iostream>
//#include <vector>
//using namespace std;
//int arr[31623] = { 0 };//if number is circular prime
//vector<int>primes;
//void prime() {
//	for (int i = 2; i < 31623; i++) {
//		if (arr[i] == 0) {
//			primes.push_back(i);
//			for (int j = 2 * i; j < 31623; j = j + i) {
//				arr[j] = 1;
//			}
//		}
//	}
//}
//int main() {
//	prime();
//	int n;
//	while (cin >> n) {
//		if (n == 0)
//			return 0;
		//totient function
//		double prod = n;
//		for (int i = 0; i < primes.size() && primes[i] <= n; i++) {
//			if (n % primes[i] == 0) {
//				do {
//					n /= primes[i];
//				} while (n % primes[i] == 0);
//				prod *= (1.0 - 1.0 / primes[i]);
//			}
//		}
//		if (n > 1)
//			prod *= (1.0 - 1.0 / n);
//		// output
//
//		cout << ((int)(prod)) << endl;
//
//	}
//	return 0;
//}