#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int n, q;
	string input;
	while (cin >> n >> q) {
		int *a = new int[n];
		memset(a, 0, sizeof(int)*n);
		int *b = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> input >> l >> r;
			if (input == "add") {
				for (int j = l - 1; j < r; j++) {
					a[j]++;
				}
			}
			else if (input == "query") {
				int sum = 0;
				for (int j = l - 1; j < r; j++) {
					sum += floor(((double)a[j]) / b[j]);
				}
				cout << sum << endl;
			}
		}
	}
	return 0;	
}