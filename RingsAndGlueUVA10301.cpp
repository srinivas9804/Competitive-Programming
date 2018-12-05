#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
using namespace std;
class Point {
public:
	double x, y;
	Point(double a, double b);
	Point();
};
Point::Point( double a,  double b) {
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

Point points[100];
int set[100];
int maximum = 1;
int find(int element) {
	if (set[element] < 0)
		return element;
	return set[element] = find(set[element]);
}
void UnionSet(int r1, int r2) {
	set[r1] += set[r2];
	maximum = maximum < set[r1] ? maximum : set[r1];
	set[r2] = r1;
}
void Union(int element1, int element2) {
	int root1 = find(element1);
	int root2 = find(element2);
	if (root1 == root2)
		return;
	if (set[root1] < set[root2]) {//root1 has more members
		UnionSet(root1, root2);
	}
	else {
		UnionSet(root2, root1);
	}

}
int main() {
	//freopen("myfile.txt", "w", stdout);
	int n;
	double radius[100];
	while (cin >> n) {
		maximum = 1;
		if (n == 0)
			maximum = 0;
		if (n == -1)
			return 0;
		memset(&set, -1, sizeof(int)*(n + 1));
		for (int i = 0; i < n; i++) {
			cin >> points[i].x >> points[i].y >> radius[i];
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (find(i) != find(j)) {//points are not in the same set
					double d = distance(points[i], points[j]);
					if (d <= radius[i] + radius[j] &&  radius[i]<=d+radius[j] && radius[j]<=d+radius[i]) {
						Union(i, j);
					}
				}
			}
		}
		if (abs(maximum) == 1) 
			cout << "The largest component contains " << abs(maximum) << " ring." << endl;
		else
			cout << "The largest component contains "<<abs(maximum)<<" rings." << endl;
	}
	return 0;
}