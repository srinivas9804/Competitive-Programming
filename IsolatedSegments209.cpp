#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <iomanip>
#include <algorithm>
//#include <fstream>
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
Point startPoint[100];
Point endPoint[100];
Point smallest;
int smallestIndex;
int determinant(Point p1, Point p2) {
	return (p1.x*p2.y - p2.x*p1.y);
}
int AntiClockWise(Point p1, Point p2, Point p3) {
	int val = determinant(p1, p2) + determinant(p2, p3) + determinant(p3, p1);
	if (val > 0)
		return 1;
	else if (val < 0)
		return -1;
	else
		return 0;
}
double distance(Point p1, Point p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
bool onSegment(Point p, Point q, Point r){//checks if point q lies on line pr
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;
	return false;
}

int main() {
	int n;
	int ctr = 1;
	cin >> n;
	//ofstream myfile;
	//myfile.open("output.txt");
	bool flag[100];
	for (int z = 0; z < n; z++) {
		int m;
		cin >> m;
		fill(begin(flag), end(flag), false);
		for (int i = 0; i < m; i++) {
			cin >> startPoint[i].x >> startPoint[i].y >> endPoint[i].x >> endPoint[i].y;
		}
		int ctr = 0;
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				int ctr = AntiClockWise(startPoint[i], endPoint[i], startPoint[j]);
				int ctr1 = AntiClockWise(startPoint[i], endPoint[i], endPoint[j]);
				int ctr2 = AntiClockWise(startPoint[j], endPoint[j], startPoint[i]);
				int ctr3 = AntiClockWise(startPoint[j], endPoint[j], endPoint[i]);
				if (ctr!=ctr1  && ctr2!=ctr3 ) {
					flag[i] = true;
					flag[j] = true;
				}
				if (ctr == 0) {//on the same line. startPoint[i],endPoint[i],startPoint[j] are coolinear
					//check if the startpoint[j] lies in between
					Point a = startPoint[i];
					Point b = endPoint[i];
					Point c = startPoint[j];
					if (onSegment(a,c,b)) {
						flag[i] = true;
						flag[j] = true;
						continue;
					}					
				}
				if (ctr1 == 0) {//startPoint[i],endPoint[i],endPoint[j]
					double lineDist = distance(startPoint[i], endPoint[i]);
					Point a = startPoint[i];
					Point b = endPoint[i];
					Point c = endPoint[j];
					
					double dotproduct = (c.x - a.x) * (b.x - a.x) + (c.y - a.y)*(b.y - a.y);
					if (onSegment(a, c, b)) {
						flag[i] = true;
						flag[j] = true;
						continue;
					}
				}
				if (ctr2 == 0) {//startPoint[j],endPoint[j],startPoint[i]
					//check if the startpoint[i] lies in between
					Point a = startPoint[j];
					Point b = endPoint[j];
					Point c = startPoint[i];
					
					if (onSegment(a, c, b)) {
						flag[i] = true;
						flag[j] = true;
						continue;
					}
				}
				if (ctr3 == 0) {//startPoint[j],endPoint[j],endPoint[i]
					Point a = startPoint[j];
					Point b = endPoint[j];
					Point c = endPoint[i];

					if (onSegment(a, c, b)) {
						flag[i] = true;
						flag[j] = true;
						continue;
					}
				}
			}
			if (!flag[i])
				ctr++;
		}
		cout << ctr << endl;
		//myfile << ctr << endl;
	}
	return 0;
}