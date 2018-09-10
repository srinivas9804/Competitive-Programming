//#include <iostream>
//#include <queue>
//using namespace std;
//int arr[10000] = { 0 };
//void prime() {
//	for (int i = 2; i < 10000; i++) {
//		if (arr[i] == 0) {
//			for (int j = 2 * i; j < 10000; j=j+i) {
//				arr[j] = 1;
//			}
//		}
//	}
//}
//int main() {
//	prime(); 
//	int t = 0;
//	cin >> t;
//	int visited[10000] = { 0 };
//	for (int i = 1; i <= t; i++) {
//		queue<int>q;
//		bool flag = true;
//		bool flag1 = true;
//		int start, end;
//		int ctr = 0;
//		cin >> start >> end;	
//		q.push(start);
//		int count = q.size();
//		while (!q.empty() && flag1) {
//			if (--count == 0) {
//				if (flag == true) {
//					count++;
//					flag = false;
//				}
//				else {
//					ctr++;
//					count = q.size();
//				}
//			}
//			int x = q.front();
//			if (x == end) {//happens only if the end == start in the first iteration
//				flag1 = false;
//				break;
//			}
//			q.pop();
//			int ones = x % 10;
//			int tens = (x / 10) % 10;
//			int hundreds = (x / 100) % 10;
//			int thousands = (x / 1000) % 10;
//			for (int j = 0; j < 10; j++) {
//				int index = 0;
//				index = thousands * 1000 + hundreds * 100 + tens * 10 + j;
//				if (arr[index] == 0 && visited[index] != i) {
//					if (index == end) {
//						ctr++;
//						flag1 = false;
//						break;
//					}
//					visited[index] = i;
//					q.push(index);
//				}
//				index = thousands * 1000 + hundreds * 100 + j * 10 + ones;
//				if (arr[index] == 0 && visited[index] != i) {
//					if (index == end) {
//						ctr++;
//						flag1 = false;
//						break;
//					}
//					visited[index] = i;
//					q.push(index);
//				}
//				index = thousands * 1000 + j * 100 + tens * 10 + ones;
//				if (arr[index] == 0 && visited[index] != i) {
//					if (index == end) {
//						ctr++;
//						flag1 = false;
//						break;
//					}
//					visited[index] = i;
//					q.push(index);
//				}
//				if (j != 0) {
//					index = j * 1000 + hundreds * 100 + tens * 10 + ones;
//					if (arr[index] == 0 && visited[index] != i) {
//						if (index == end) {
//							ctr++;
//							flag1 = false;
//							break;
//						}
//						visited[index] = i;
//						q.push(index);
//					}
//				}
//			}
//			if (count == 0) {
//				count = q.size();
//			}
//		}
//		if (flag1 == true)
//			cout << "Impossible" << endl;
//		else
//			cout << ctr << endl;
//	}
//	return 0;
//}