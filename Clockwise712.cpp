//#include <iostream>
//#include <cstdlib>
//#include <math.h>
//#include <stack>
//#include <algorithm>
//using namespace std;
//class Point {
//public:
//	int x, y;
//	Point(int a, int b);
//	Point();
//};
//Point::Point(int a, int b) {
//	x = a;
//	y = b;
//}
//Point::Point() {
//	x = y = 0;
//}
//int determinant(Point p1, Point p2) {
//	return p1.x*p2.y - p2.x*p1.y;
//}
//double distance(Point p1, Point p2) {
//	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
//}
//int AntiClockwise(Point p1, Point p2, Point p3) {
//	int val = determinant(p1, p2) + determinant(p2, p3) + determinant(p3, p1);
//	if (val > 0)
//		return 1;
//	else if (val < 0)
//		return -1;
//	return 0;
//}
//Point smallest;
//int compare(const void* a, const void* b) {
//	Point* p1 = (Point*)a;
//	Point* p2 = (Point*)b;
//	int angle = AntiClockwise(smallest, *p1, *p2);
//	if (angle < 0)
//		return 1;
//	else if (angle > 0)
//		return -1;
//	else {
//		if (distance(smallest, *p2) > distance(smallest, *p1)) {
//			return -1;
//		}
//		else
//			return 1;
//	}
//}
//int compare1(const void* a, const void* b) {
//	Point* p1 = (Point*)a;
//	Point* p2 = (Point*)b;
//	int angle = AntiClockwise(smallest, *p1, *p2);
//	if (angle < 0)
//		return -1;
//	else if (angle > 0)
//		return 1;
//	else {
//		if (distance(smallest, *p2) > distance(smallest, *p1)) {
//			return -1;
//		}
//		else
//			return 1;
//	}
//}
//bool onSegment(Point p, Point q, Point r) {
//	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
//		return true;
//	return false;
//}
//int main() {
//	Point points[300];
//	int n;
//	while (cin >> n) {
//		if (n == 0)
//			break;
//		for (int i = 0; i < n; i++)
//			cin >> points[i].x >> points[i].y;
//		int ctr = 0;
//		stack<Point> s;
//		s.push(points[0]);
//		s.push(points[1]);
//		for (int i = 2; i <n; i++) {
//			Point tmp = s.top();
//			s.pop();
//			Point tmp2 = s.top();
//			s.pop();
//			if (AntiClockwise(tmp, tmp2, points[i]) < 0) {// clockwise
//				ctr++;
//				s.push(tmp);
//				s.push(tmp2);
//			}
//			if (AntiClockwise(tmp, tmp2, points[i]) == 0 && !onSegment(tmp, points[i], tmp2)) {//angle is 0
//				ctr++;
//				s.push(tmp);
//				s.push(tmp2);
//			}
//			else {
//				s.push(tmp2);
//				s.push(points[i]);
//			}
//		}
//		s = stack<Point>();
//		s.push(points[0]);
//		s.push(points[1]);
//		int ctr1 = 0;
//		for (int i = 2; i < n; i++) {
//			Point tmp = s.top();
//			s.pop();
//			Point tmp2 = s.top();
//			s.pop();
//			if (AntiClockwise(tmp, tmp2, points[i]) > 0) {//anticlockwise
//				ctr1++;
//				s.push(tmp);
//				s.push(tmp2);
//			}
//			if (AntiClockwise(tmp, tmp2, points[i]) == 0 && onSegment(tmp, points[i], tmp2)) {// angle is 180
//				ctr1++;
//				s.push(tmp);
//				s.push(tmp2);
//			}
//			else {
//				s.push(tmp2);
//				s.push(points[i]);
//			}
//		}
//		if (ctr < ctr1) {
//			if (ctr == 0) {
//				cout << "CC" << endl;
//			}
//			else
//				cout << "Remove " << ctr << " bead(s), " << "CC" << endl;
//		}
//		else {
//			if (ctr1 == 0) {
//				cout << "C" << endl;
//			}
//			else
//				cout << "Remove " << ctr1 << " bead(s), " << "C" << endl;
//		}
//	}
//	return 0;
//}