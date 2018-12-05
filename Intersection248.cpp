#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;
#define INF 10000
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
double distance(Point p1, Point p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
bool onSegment(Point p, Point q, Point r) {//checks if point q lies on line pr
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;
	return false;
}
bool intersect(Point p1, Point p2, Point q1, Point q2) {
	int ctr = AntiClockWise(p1, p2, q1);
	int ctr1 = AntiClockWise(p1, p2, q2);
	int ctr2 = AntiClockWise(q1, q2, p1);
	int ctr3 = AntiClockWise(q1, q2, p2);
	if (ctr != ctr1 && ctr2 != ctr3) {
		return true;
	}
	if (ctr == 0 && onSegment(p1, q1, p2)) {//on the same line. p1,p2,q1 are coolinearcheck if the q1 lies in between
		return true;
	}
	if (ctr1 == 0 && onSegment(p1, q2 ,p2)) {//p1,p2,q2
		return true;
	}
	if (ctr2 == 0 && onSegment(q1, p1, q2)) {//q1,q2,p1
					//check if the p1 lies in between
		return true;
	}
	if (ctr3 == 0 && onSegment(q1, p2, q2)) {//q1,q2,p2
		return true;
	}
	return false;
}
bool isInside(Point polygon[], int n, Point p) {// only returns if the point lies in the polygon. doesn't cover conrner points/vertices
	// for this function to work vertices must be in some arbitrary direction
	if (n < 3)  
		return false;
	Point extreme(INF, p.y);
	int count = 0, i = 0;
	do {
		int next = (i + 1) % n;
		if (intersect(polygon[i], polygon[next], p, extreme)) {
			if(AntiClockWise(polygon[i],p,polygon[next])==0)
				return onSegment(polygon[i], p, polygon[next]);
			count++;
		}
		i = next;
	} while (i != 0);
	return count & 1;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		Point polygon[4];
		Point line_start;
		Point line_end;
		Point top_left;
		Point bottom_right;
		cin >> line_start.x >> line_start.y >> line_end.x >> line_end.y >> top_left.x >> top_left.y >> bottom_right.x >> bottom_right.y ;
		Point bottom_left(top_left.x, bottom_right.y);
		Point top_right(bottom_right.x, top_left.y);
		polygon[0] = bottom_left;
		polygon[1] = bottom_right;
		polygon[2] = top_right;
		polygon[3] = top_left;
		if (intersect(line_start, line_end, top_left, top_right) ||
			intersect(line_start, line_end, top_left, bottom_left) ||
			intersect(line_start, line_end, bottom_left, bottom_right) ||
			intersect(line_start, line_end, bottom_right, top_right))
			cout << 'T' << endl;
		else {// line segment doesn't intersect, check if the line is within the rectangle, check if one of the endpoints is in the rectange
			if (isInside(polygon, 4, line_start))
				cout << 'T' << endl;
			else
				cout << 'F' << endl;
		}
	}
	return 0;
}