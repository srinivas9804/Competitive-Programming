#include <iostream>
#include <limits.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *arr = new int[n];
		int index = 0;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (flag && arr[i] != -1) {
				index = i;
				flag = false;
			}
		}
		int element = arr[index];
		bool flag2 = false;
		bool flag3 = false;
		bool impossible = false;
		int mod_value = -1;
		for (int i = index+1; i < n; i++) {
			if (arr[i] != -1) {
				if (flag2) {
					if (arr[i] > mod_value) {
						impossible = true;
						break;
					}
				}
				if (i - index != arr[i] - element) {
					if (!flag2) {
						int index1 = i - arr[i];
						if (index1 < index ||(index1== index && element == 1)) {
							impossible = true;
							break;
						}
						mod_value = element + (index1 - index);
						flag2 = true;
					}
					else {
						if (((element + (i - index)) % mod_value) != arr[i]) {
							impossible = true;
							break;
						}
					}
				}
				element = arr[i];
				index = i;
			}
		}
		if (impossible)
			cout << "impossible" << endl;
		else if (mod_value == -1)
			cout << "inf" << endl;
		else
			cout << mod_value << endl;
	}
	return 0;
}