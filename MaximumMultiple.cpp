#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		if (n < 3) {
			printf("-1\n");
			continue;
		}
		long long int max = -1;
		if (n % 2 == 0 && n % 3 == 0 && n % 6 == 0) {
			max = (max > n / 2 * n / 3 * n / 6)?max: (n / 2 * n / 3 * n / 6);
		}
		
		if (n % 2 == 0 && n % 4 == 0) {
			max = max > n / 2 * n / 4 * n / 4? max : n / 2 * n / 4 * n / 4;
		}
		if (n % 3 == 0) {
			max = max > n / 3 * n / 3 * n / 3 ? max : n / 3 * n / 3 * n / 3;
		}
		printf("%lld\n", max);
	}
	return 0;
}