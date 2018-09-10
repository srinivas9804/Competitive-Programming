//#include <iostream>
//#include <sstream>
//#include <string>
//using namespace std;
//int arr[22][22];//max number of characters;
//int from[22][22];//for backtracking. 1-go up. 2-go left. 3. up and left
//string str1;
//string str2;
//int main() {
//	while (cin >> str1) {
//		if (str1[0] == '#')
//			return 0;
//		cin >> str2;
//		int n = str1.length();
//		int m = str2.length();
//		for (int i = 0; i <= n; i++) {
//			for (int j = 0; j <= m; j++) {
//				arr[i][j] = 0;
//				from[i][j] = 0;
//			}
//		}
//		for (int i = 0; i <= n; i++) {
//			for (int j = 0; j <= m; j++) {
//				if (i == 0) {
//					arr[i][j] = j;
//					from[i][j] = 1;
//				}
//				else if (j == 0) {
//					arr[i][j] = i;
//					from[i][j] = 2;
//				}
//				else {
//					if (arr[i - 1][j] < arr[i][j - 1]) {
//						if (arr[i - 1][j] < arr[i - 1][j - 1]) {
//							arr[i][j] = arr[i - 1][j];
//							from[i][j] = 2;//delete character
//						}
//						else {
//							arr[i][j] = arr[i - 1][j - 1];
//							from[i][j] = 3;//change
//						}
//					}
//					else {
//						if (arr[i][j - 1] < arr[i - 1][j - 1]) {
//							arr[i][j] = arr[i][j - 1];
//							from[i][j] = 1;//insert
//						}
//						else {
//							arr[i][j] = arr[i - 1][j - 1];
//							from[i][j] = 3;
//						}
//					}
//					arr[i][j]++;
//					if (str1[i - 1] == str2[j - 1] && from[i][j] == 3) {
//						from[i][j] = 0;
//						arr[i][j]--;
//					}
//				}
//			}
//		}
//		string output = "E";
//		while (!(m == 0 && n == 0)) {
//			if (from[n][m] == 0) {
//				m = m - 1;
//				n = n - 1;
//				continue;
//			}
//			else if (from[n][m] == 2) {
//				string temp = "D";
//				temp += str1[n - 1];
//				stringstream ss;
//				if (m + 1 < 10)
//					temp += '0';
//				ss << (m+1);
//				temp += ss.str();
//				output = temp + output;
//				n = n - 1;
//			}
//			else if (from[n][m] == 1) {
//				string temp = "I";
//				temp += str2[m - 1];
//				stringstream ss;
//				if (m  < 10)
//					temp += '0';
//				ss << m;
//				temp += ss.str();
//				output = temp + output;
//				m = m - 1;
//			}
//			else {
//				string temp = "C";
//				temp+= str2[m - 1];
//				stringstream ss;
//				if (m  < 10)
//					temp += '0';
//				ss << m;
//				temp += ss.str();
//				output = temp + output;
//				m = m - 1;
//				n = n - 1;
//			}
//		}
//		cout << output << endl;
//	}
//	return 0;
//}