#include <iostream>
#include <queue>
using namespace std;
//USE BFS not DFS. You need the answer with the lowest steps.
class values {
public:
	int v1;
	int v2;
	int v3;
	int v4;
	values();
	values(int, int, int, int);
};
values::values() {
	v1 = 0; v2 = 0; v3 = 0; v4 = 0;
}
values::values(int n1, int n2, int n3, int n4) {
	v1 = n1;
	v2 = n2;
	v3 = n3;
	v4 = n4;
}
class cup {
public:
	int capacity;
	int value;
	cup();
	bool isFull();
	bool isEmpty();
};
cup::cup() {
	capacity = 0;
	value = 0;
}
bool cup::isFull() {
	if (value == capacity)
		return true;
	else
		return false;
}
bool cup::isEmpty() {
	if (value == 0)
		return true;
	else
		return false;
}

queue <values>q;
cup cups[4];
int arr[25][25][25][25] = {0};
int num = 0;
int t = 0;
int find(int val) {
	values v;
	bool flag = true;
	int ctr = 0;// ctr is used to keep track of depth
	q.push(v);
	int count = q.size();
	while (!q.empty()) {
		if (--count == 0) {
			if (flag == true) {// ignore the root because whenever we travel to a new node we immediately return the result
				count++;
				flag = false;
			}
			else {
				ctr++;
				count = q.size();
			}
		}
		values x = q.front();
		q.pop();
		
		cups[0].value = x.v1;
		cups[1].value = x.v2;
		cups[2].value = x.v3;
		cups[3].value = x.v4;
		for (int i = 0; i < 4; i++) {
			if (!(cups[i].isFull())) {//fill cups.
				int temp = cups[i].value;
				cups[i].value = cups[i].capacity;				
				if (cups[i].value == t) {
					return ctr+1;
				}
				if (arr[cups[0].value][cups[1].value][cups[2].value][cups[3].value] != num) {
					arr[cups[0].value][cups[1].value][cups[2].value][cups[3].value] = num;
					values temp1(cups[0].value, cups[1].value, cups[2].value, cups[3].value);
					q.push(temp1);
				}
				cups[i].value = temp;
			}
			if (!(cups[i].isEmpty())) {//Empty a cup
				int temp = cups[i].value;
				cups[i].value = 0;
				if (arr[cups[0].value][cups[1].value][cups[2].value][cups[3].value] != num) {
					arr[cups[0].value][cups[1].value][cups[2].value][cups[3].value] = num;
					values temp1(cups[0].value, cups[1].value, cups[2].value, cups[3].value);
					q.push(temp1);
				}
				cups[i].value = temp;
			}
			for (int j = 0; j < 4; j++) {//pouring from [i] to [j]
				if (i == j)
					continue;
				if (!cups[j].isFull() && !cups[i].isEmpty()) {
					int temp1 = cups[i].value;
					int temp2 = cups[j].value;
					int add_value = cups[j].capacity - cups[j].value;//value that can be added
					int pour_value = cups[i].value;//amount of flour that can be poured
					if (add_value >= pour_value) {
						cups[i].value = 0;
						cups[j].value += pour_value;
						if (cups[j].value == t) {
							return ctr+1;
						}
					}
					else {
						cups[j].value = cups[j].capacity;
						cups[i].value -= add_value;
						if (cups[i].value == t) {
							return ctr+1;
						}
					}
					if (arr[cups[0].value][cups[1].value][cups[2].value][cups[3].value] != num) {
						arr[cups[0].value][cups[1].value][cups[2].value][cups[3].value] = num;
						values temp1(cups[0].value, cups[1].value, cups[2].value, cups[3].value);
						q.push(temp1);
					}
					cups[i].value = temp1;
					cups[j].value = temp2;
				}
			}
		}
		if (count == 0) {
			count = q.size();
		}
	}
	return -1;
}
int main() {
	while (cin >> cups[0].capacity >> cups[1].capacity >> cups[2].capacity >> cups[3].capacity >> t) {
		num++;
		q = queue<values>();
		cups[0].value = 0;
		cups[1].value = 0;
		cups[2].value = 0;
		cups[3].value = 0;
		arr[0][0][0][0] = num;
		int val = find(0);
		cout << val << endl;
	}
	return 0;
}