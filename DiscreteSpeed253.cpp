#include <iostream>
#include <string.h>
#include <queue>
#include <iomanip>
#include <limits.h>
using namespace std;
class Edge {
public:
	double distance;
	int speedLimit;
	Edge();
};
Edge::Edge() {
	distance = 0.0;
	speedLimit = 0;
}
class City {
public:
	int index;
	int from_index;
	double totaltime;
	int currentSpeed;
	City();
	bool operator<(const City &other)const {
		return totaltime>other.totaltime;
	}
};
City::City() {
	index = -1;
	totaltime = 0;
	currentSpeed = 0;
}
int visited[40][40][40];//index and speed
int main() {
	int n, m;
	while (cin >> n >> m) {
		bool flag = false;
		double min_time = 0.0;
		if (n == 0 && m == 0)
			return 0;
		int start, end;
		Edge edges[40][40];
		cin >> start >> end;
		for (int i = 0; i < m; i++) {
			int x, y, d, c;
			cin >> x >> y >> d >> c;
			edges[x][y].distance = d;
			edges[y][x].distance = d;
			edges[x][y].speedLimit = c;
			edges[y][x].speedLimit = c;
		}
		memset(visited, 0, sizeof(visited));
		priority_queue<City> q;
		City c;
		c.index = start;
		c.totaltime = 0.0;
		c.currentSpeed = 0;
		c.from_index = 0;
		q.push(c);
		visited[start][0][0] = 1;
		while (!q.empty()) {
			City city = q.top();
			q.pop();
			int from = city.from_index;
			for (int i = 1; i <= n; i++) {//speed+1
				if (i == from)
					continue;
				if (edges[city.index][i].distance != 0.0 && edges[city.index][i].speedLimit != 0) {
					int speed = city.currentSpeed + 1;
					double distance = edges[city.index][i].distance;
					int limit = edges[city.index][i].speedLimit;
					double time = city.totaltime + (distance / speed);
					if (speed <= limit) {
						if (visited[i][speed][city.index] == 0 ) {
							City temp;
							temp.currentSpeed = speed;
							temp.index = i;
							temp.totaltime += time;//time taken to reach previous node + time to reach the new node
							temp.from_index = city.index;
							q.push(temp);
							if (i == end && speed == 1) {
								if (!flag || temp.totaltime < min_time) {
									min_time = temp.totaltime;
									flag = true;
								}
							}
							visited[i][speed][city.index] = 1;
						}
					}
				}
			}
			if (city.index == start && city.currentSpeed == 0) {// for the first node, speed must be 1
				continue;
				//starting speed should be 1;
			}
			for (int i = 1; i <= n; i++) {//speed
				if (i == from)
					continue;
				if (edges[city.index][i].distance != 0.0 && edges[city.index][i].speedLimit != 0) {
					int speed = city.currentSpeed;
					double distance = edges[city.index][i].distance;
					int limit = edges[city.index][i].speedLimit;
					double time = city.totaltime + (distance / speed);
					if (speed <= limit) {
						if (visited[i][speed][city.index] == 0 ) {
							City temp;
							temp.currentSpeed = speed;
							temp.index = i;
							temp.totaltime += time;//time taken to reach previous node + time to reach the new node
							temp.from_index = city.index;
							q.push(temp);
							if (i == end && speed == 1) {
								if (!flag || temp.totaltime < min_time) {
									min_time = temp.totaltime;
									flag = true;
								}
							}
							visited[i][speed][city.index] = 1;
						}
					}
				}
			}
			if (city.currentSpeed == 1)//speed shouldn't go to 0
				continue;
			for (int i = 1; i <= n; i++) {//speed
				if (i == from)
					continue;
				if (edges[city.index][i].distance != 0.0 && edges[city.index][i].speedLimit != 0) {
					int speed = city.currentSpeed - 1;
					double distance = edges[city.index][i].distance;
					int limit = edges[city.index][i].speedLimit;
					double time = city.totaltime + (distance / speed);
					if (speed <= limit) {
						if (visited[i][speed][city.index] == 0 ) {
							City temp;
							temp.currentSpeed = speed;
							temp.index = i;
							temp.totaltime += time;//time taken to reach previous node + time to reach the new node
							temp.from_index = city.index;
							q.push(temp);
							if (i == end && speed == 1) {
								if (!flag || temp.totaltime < min_time) {
									min_time = temp.totaltime;
									flag = true;
								}
							}
							visited[i][speed][city.index] = 1;
						}
					}
				}
			}
		}
		if (!flag)
			cout << "unreachable" << endl;
		else
			cout << fixed << setprecision(5) << min_time << endl;
	}
	return 0;
}