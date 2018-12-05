#include <iostream>
using namespace std;
class Point {
public:
	int x, y;
	Point(int a, int b);
	Point();
};
Point::Point(int a, int b) {
	x = a;
	y = b;
}
Point::Point() {
	x = y = 0;
}
int determinant(Point p1, Point p2) {
	return (p1.x*p2.y - p2.x*p1.y);
}
int main() {
	int p; 
	Point set1[100000];
	while (cin >> p) {
		for (int i = 0; i < p; i++) {
			cin >> set1[i].x >> set1[i].y;
		}
		int r;
		cin >> r;
		for (int h = 0; h < r; h++) {
			int x, y;
			cin >> x >> y;
			Point point(x,y);
			bool flag = false;
			for (int i = 0; i < p && !flag; i++) {
				for (int j = i+1; j < p && !flag; j++) {
					for (int k = j+1; k < p && !flag; k++) {
						Point p1 = set1[i];
						Point p2 = set1[j];
						Point p3 = set1[k];
						//(x1y2 - x2y1) + (x2y3 - x3y2) + (x3y1 - x1y3) > 0 anticlockwise turning condition 
						//Use Determinant
						int check1 = determinant(p1, p2) + determinant(p2, point) + determinant(point, p1);
						int check2 = determinant(p3, p2) + determinant(p2, point) + determinant(point, p3);
						if (check1*check2 <= 0) {
							check1 = determinant(p2, p1) + determinant(p1, point) + determinant(point, p2);
							check2 = determinant(p3, p1) + determinant(p1, point) + determinant(point, p3);
							if (check1*check2 <= 0) {
								check1 = determinant(p1, p3) + determinant(p3, point) + determinant(point, p1);
								check2 = determinant(p2, p3) + determinant(p3, point) + determinant(point, p2);
								if (check1*check2 <= 0) {
									flag = true;
									break;
								}
							}
						}
					}
				}
			}
			if (flag)
				cout << "inside" << endl;
			else
				cout << "outside" << endl;
		}
	}
	return 0;
}