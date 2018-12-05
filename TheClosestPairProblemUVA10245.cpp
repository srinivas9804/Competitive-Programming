#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>
#include <algorithm>
#define INF 1000000
using namespace std;
class Point {
public:
	long double x, y;
	Point(long double a, long double b);
	Point();
};
Point::Point(long double a, long double b) {
	x = a;
	y = b;
}
Point::Point() {
	x = y = 0.0;
}

int determinant(Point p1, Point p2) {
	return (p1.x*p2.y - p2.x*p1.y);
}
int AntiClockWise(Point p1, Point p2, Point p3) {
	int val = determinant(p1, p2) + determinant(p2, p3) + determinant(p3, p1);
	if (val > 0)
		return 1;//if anticlockwise
	else if (val < 0)
		return -1;
	else
		return 0;
}
long double distance(Point p1, Point p2) {
	long double d = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
	return d;
}
bool onSegment(Point p, Point q, Point r) {//checks if point q lies on line pr
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;
	return false;
}

int main() {
	int n;
	Point points[10000];
	while (cin >> n) {
		if (n == 0)
			return 0;
		for (int i = 0; i < n; i++) {
			cin >> points[i].x >> points[i].y;
		}
		long double min_distance = INF;
		for (int i = 0; i < n ; i++) {
			for (int j = i + 1; j < n; j++) {
				long double d = distance(points[i], points[j]);
				if (d < min_distance)
					min_distance = d;
			}
		}
		if (min_distance >= 10000.00) {
			cout << "INFINITY" << endl;
		}
		else
			cout << fixed << setprecision(4) << min_distance << endl;
	}
	return 0;
}