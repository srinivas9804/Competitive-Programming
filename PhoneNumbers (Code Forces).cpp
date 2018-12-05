#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i<n; i++) {
			cin >> a[i];
		}
		int *b = new int[n];
		for (int i = 0; i<n; i++) {
			cin >> b[i];
		}
		int *c = new int[n];
		for (int i = 0; i<n; i++) {
			c[i] = 0;
		}
		bool flag = true;
		for (int i = 0; i<n - 2; i++) {
			int sum = b[i] - a[i] - c[i];
			if (sum == 0)
				continue;
			if (sum < 0) {
				flag = false;
				break;
			}
			c[i] += sum;
			c[i+1] += sum + 1;
			c[i+2] += sum + 2;
		}
		for (int i = n - 2; i<n; i++) {
			if (c[i] != b[i]) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;
	}
	return 0;
}
