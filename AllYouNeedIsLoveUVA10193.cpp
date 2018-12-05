#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
int gcd(int p, int q, int *x, int *y) {
	int x1, y1;
	int g;
	if (q > p)
		return gcd(q, p, y, x);
	if (q == 0) {
		*x = 1;
		*y = 0;
		return(p);
	}
	g = gcd(q, p%q, &x1, &y1);
	*x = y1;
	*y = (x1 - floor(p / q)*y1);
	return g;
}
int main() {
	string input;
	getline(cin, input);
	stringstream s(input);
	int t;
	s >> t;
	int ctr = 1;
	while (t--) {
		string str1;
		string str2;
		getline(cin, str1);
		getline(cin, str2);
		int num1 = 0, num2 = 0;
		for (int i = str1.length()-1; i >= 0; i--) {
			num1 += (str1[i] - '0')*pow(2, str1.length() - 1 - i);
		}
		for (int i = str2.length() - 1; i >= 0; i--) {
			num2 += (str2[i] - '0')*pow(2, str2.length() - 1 - i);
		}
		int x=0,y=0;
		int val = gcd(num1, num2, &x, &y);
		if (val == 1) {
			cout << "Pair #" << ctr++ << ": Love is not all you need!"<<endl;
		}
		else {
			cout << "Pair #" << ctr++ << ": All you need is love!"<<endl;
		}
	}
	return 0;
}