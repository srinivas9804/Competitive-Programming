#include <iostream>
#include <list>
#include <math.h>
using namespace std;
#define MAX 1000000000

int sum_of_digits(int num) {
	int sum = 0;
	while (num > 0) {
		int d = num % 10;
		sum += d;
		num /= 10;
	}
	return sum;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		for (int i = num + 1;; i++) {
			int sum1 = sum_of_digits(i);
			int sum2 = 0;
			int n = i;
			bool flag = false;
			for (int j = 2; j <= (int)sqrt(n); j++) {
				if (n%j == 0) {
					int c = sum_of_digits(j);
					flag = true;
					while (n%j == 0) {
						n /= j;
						sum2 += c;
					}
				}
			}
			if (n != 1) {
				sum2 += sum_of_digits(n);
			}
			if (sum1 == sum2 && flag) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}