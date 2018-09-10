//#include <iostream>
//using namespace std;
//
//int main() {
//	int n = 0;
//	char name[100][16];
//	int day[100];
//	int month[100];
//	int year[100];
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> name[i] >> day[i] >> month[i] >> year[i];
//	}
//	int largest = 0;
//	int smallest = 0;
//	for (int i = 1; i<n; i++) { 
//		if (year[i] <= year[smallest]) {
//			if (year[i]<year[smallest])
//				smallest = i;
//			else if (month[i] <= month[smallest]) {
//				if (month[i]<month[smallest]) {
//					smallest = i;
//				}
//				else if (day[i] <= day[smallest])
//					smallest = i;
//			}
//		}
//		if (year[i] >= year[largest]) {
//			if (year[i]>year[largest])
//				largest = i;
//			else if (month[i] >= month[largest]) {
//				if (month[i]>month[largest]) {
//					largest = i;
//				}
//				else if (day[i] >= day[largest])
//					largest = i;
//			}
//		}
//	}
//	cout << name[largest]<<endl << name[smallest]<<endl;
//	return 0;
//}