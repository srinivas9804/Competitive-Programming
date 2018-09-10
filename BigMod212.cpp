//#include <iostream>
//#include <math.h>
//using namespace std;
//int ModExp(int a,int b,int c) {//a^b mod c
//	a %= c;
//	if (b == 0)
//		return 1;
//	if (b == 1)
//		return a;
//	int temp= ModExp(a, b >> 1, c);
//	temp = (temp*temp) % c;
//	if (b & 1)
//		temp = (temp*a) % c;
//	return temp;
//}
//int main() {
//	int b, p, m;
//	while (cin >> b >> p >> m) {
//		int r = ModExp(b, p,m);	
//		cout << r << endl;
//	}
//
//	return 0;
//}