#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <iomanip>
#include <queue>
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
Point points[100];
Point smallest;
int smallestIndex;
int determinant(Point p1, Point p2) {
	return (p1.x*p2.y - p2.x*p1.y);
}
int AntiClockWise(Point p1, Point p2, Point p3) {
	return determinant(p1, p2) + determinant(p2, p3) + determinant(p3, p1);
}
double distance(Point p1, Point p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
int compare(const void* a, const void* b) {// sorting points based on their angle
	Point* p1 = (Point*)a;
	Point* p2 = (Point*)b;
	int angle = AntiClockWise(smallest, *p1, *p2);
	if (angle < 0)//anticlockwise
		return 1;//Sorting in descending order
	else if (angle > 0)//clockwise
		return -1;
	else {// collinear. have to check if angle is 0 or 180
		  //If the distance from the smallest point to the point2 is greater than the distance from point1 to point2
		  //Then the angle is 0 degrees otherwise it is 180
		if (distance(smallest, *p2) > distance(smallest, *p1))
			return -1;
		else
			return 1;
	}// For this program do not have to consider this portion because no three points are collinear

}
int main() {
	int n;
	int ctr = 1;
	while (cin >> n) {
		Point origin;
		if (n == 0)
			return 0;
		double tile_area = 0.0;
		for (int i = 0; i < n; i++) {
			cin >> points[i].x >> points[i].y;
			if (i == 0)
				smallest = points[i];
			else if (points[i].y < smallest.y)
				smallest = points[i];
			if (i > 0) {
				tile_area += determinant(points[i - 1], points[i]);
			}
		}
		tile_area += determinant(points[n - 1], points[0]);
		tile_area = fabs(tile_area) / 2;
		qsort(points, n, sizeof(Point), compare);
		stack<int> s1;//storing the index in the array would make more sense
		s1.push(0);
		s1.push(1);
		for (int i = 2; i < n; i++) {
			int p2 = s1.top();
			s1.pop();
			int p1 = s1.top();
			if (AntiClockWise(points[p1], points[p2], points[i]) > 0) {
				s1.push(p2);
				s1.push(i);
			}
			else {
				i--;//check point again
			}
		}
		/*while (!s.empty()) {
		cout << s.top().x<<" "<<s.top().y<<endl;
		s.pop();
		}*/
		//Now, all the points not in the convex hull, will be the interior points. find area
		//between the edge points
		//Find area of convex hull - area of tile find area of tile before sorting;
		double total_area = 0.0;
		int first = s1.top();
		int n1 = 0;
		while (!s1.empty()) {
			n1 = s1.top();
			s1.pop();
			if (s1.empty())
				break;
			int n2 = s1.top();
			total_area += determinant(points[n1], points[n2]);
		}
		total_area += determinant(points[n1], points[first]);
		total_area = fabs(total_area) / 2;

		cout << "Tile #" << ctr++ << endl;
		cout << "Wasted Space = " << fixed << setprecision(2) << (total_area - tile_area) / total_area * 100 << " %" << endl << endl;
	}
	return 0;
}