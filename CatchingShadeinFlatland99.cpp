//#include <iostream>
//#include <iomanip>
//#include <cmath>
//#define PI 3.14159265
//using namespace std;
//
//int main() {
//	int n;
//	while (cin >> n) {
//		if (n == 0)
//			return 0;
//		int *x = new int[n];
//		int *y = new int[n];
//		int *r = new int[n];
//		for (int i = 0; i < n; i++) {
//			cin >> x[i] >> y[i] >> r[i];
//		}
//		double max = 0.0;
//		for (double i = 0.0; i <= 360.0; i += 0.25) {
//			double a = 500 * cos(i*PI / 180);
//			double b = 500 * sin(i*PI / 180);
//			double c = 0;//y intercept is zero
//			double sum = 0.0;
//			for (int j = 0; j < n; j++) {
//				double dist = (a*x[j] + b * y[j] ) / sqrt(pow(a, 2) + pow(b, 2));//perpendicular distance from the line to the center of the circle
//				if (dist < 0)
//					continue;
//				dist = x[j] * x[j] + y[j] * y[j] - dist * dist;
//				if (dist < r[j]*r[j]) {
//					sum += 2 * sqrt(pow(r[j], 2) - dist);//pythagoras
//				}
//			}
//			if (sum > max)
//				max = sum;
//		}
//		cout << setprecision(3) << fixed << max << endl;
//	}
//	return 0;
//}	