#include <iostream>
using namespace std;

int main() {
	int arr[1000];
	int m[100000];
	int n;
	while (cin >> n) {
		int total = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			total += arr[i];
		}
		for (int i = 0; i < total + 10; i++) {
			m[i] = 0;
		}
		m[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = total; j >= arr[i]; j--) {
				m[j] |= m[j - arr[i]];
			}
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if(m[arr[i]]==i)
		}
	}
	return 0;
}