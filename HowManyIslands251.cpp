//#include <iostream>
//using namespace std;
//int arr[50][50];
//int n=0, m=0;
//void land(int i,int j) {
//	arr[i][j] = -1;
//	if (i != 0) {//top
//		if(arr[i-1][j] == 1)
//			land(i - 1, j);
//	}
//	if (j != 0) {//left
//		if(arr[i][j-1] == 1)
//			land(i, j-1);
//	}
//	if (i != n - 1) {//bottom
//		if(arr[i + 1][j] == 1)
//			land(i + 1, j);
//	}
//	if (j != m - 1) {//right
//		if(arr[i][j + 1] == 1)
//			land(i, j + 1);
//	}
//	if (i != n-1 && j != m-1) {//bottom right
//		if (arr[i + 1][j +1] == 1)
//			land(i + 1, j +1);
//	}
//	if (i != n - 1 && j != 0) {//bottom left
//		if (arr[i + 1][j - 1] == 1)
//			land(i + 1, j - 1);
//	}
//	if (i != 0 && j != 0) {//top left
//		if (arr[i - 1][j - 1] == 1)
//			land(i - 1, j - 1);
//	}
//	if (i != 0 && j != m - 1) {//top right
//		if (arr[i - 1][j + 1] == 1)
//			land(i - 1, j + 1);
//	}
//}
//int main() {
//	while (cin >> m >> n) {
//		int ctr = 0;
//		if (n == 0 && m == 0)
//			break;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				cin >> arr[i][j];
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (arr[i][j] == 1) {
//					land(i,j);
//					ctr++;
//				}
//			}
//		}
//		cout << ctr << endl;
//	}
//	return 0;
//}