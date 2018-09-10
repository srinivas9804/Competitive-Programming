//#define _crt_secure_no_warnings
//#include <iostream>
//#include <cstring>
//#include <vector>
//#include <stdio.h>
//#include <math.h>
//#include <limits.h>
////#include <fstream>
//using namespace std;
//
//#define maxL (1000000>>5)+1
//#define GET(x) (mark[x>>5]>>(x&31)&1)
//#define SET(x) (mark[x>>5]|=1<<(x&31))
//int mark[maxL];
//int p[700000], pt = 0;
//void sieve() {
//	register int i, j, k;
//	SET(1);
//	int n = 1000000;
//	for (i = 2; i <= n; i++) {
//		if (!GET(i)) {
//			p[pt++] = i;
//			for (k = n / i, j = i * k; k >= i; k--, j -= i)
//				SET(j);
//		}
//	}
//}
//int check(int n) {
//	if (n < 1000000)
//		return !GET(n);
//	static int sq, i;
//	sq = (int)sqrt(n);
//	for (i = 0; i < pt && p[i] <= sq; i++)
//		if (n%p[i] == 0)
//			return 0;
//	return 1;
//}int main() {
//	sieve();
//	long long int l, u;
//	while (cin >> l >> u) {
//		long long  minimum = INT_MAX;
//		long long maximum = INT_MIN;
//		long long min1 = 0;
//		long long min2 = 0;
//		long long max1 = 0;
//		long long max2 = 0;
//		long long prev_prime = 0;
//		long long curr_prime = 0;
//		for (long long i = l; i <= u; i++) {
//			if (check(i)) {
//				if (prev_prime == 0) {
//					prev_prime = i;
//					continue;
//				}
//				curr_prime = i;
//				if (curr_prime - prev_prime < minimum) {
//					min1 = prev_prime;
//					min2 = curr_prime;
//					minimum = curr_prime - prev_prime;
//				}
//				if (curr_prime - prev_prime > maximum) {
//					max1 = prev_prime;
//					max2 = curr_prime;
//					maximum = curr_prime - prev_prime;
//				}
//				prev_prime = curr_prime;
//			}
//		}
//		if (curr_prime == 0)
//			cout << "There are no adjacent primes." << endl;
//		else
//			cout << min1 << "," << min2 << " are closest, " << max1 << ","<<max2 << " are most distant." << endl;
//	}
//	return 0;
//}