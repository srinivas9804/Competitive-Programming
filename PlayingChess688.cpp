//#include <iostream>
//#include <string>
//#include <queue>
//using namespace std;
//char arr[8][8];
//struct index {
//	int row;
//	int col;
//};
//queue <index>q;
//int check(int row, int col) {
//	if (row >= 0 && row <= 7 && col >= 0 && col <= 7 && (arr[row][col] == '-'|| arr[row][col] == '@')) {
//		index in;
//		in.row = row;
//		in.col = col;
//		q.push(in);
//		if (arr[row][col] == '@')
//			return 1;
//		arr[row][col] = '*';
//		return 0;
//	}
//	return 0;
//}
//int main() {
//	int t = 0;
//	string input;
//	cin >> t;
//	for (int i = 1; i <= t; i++) {
//		index start;
//		index end;
//		q = queue <index>();
//		for (int j = 0; j < 8; j++) {
//			getline(cin, input);
//			if(input[0]=='\0'|| input[0] == '\n')
//				getline(cin, input);
//			for (int k = 0; k < 8; k++) {
//				arr[j][k] = input[k];
//				if (input[k] == '#') {
//					start.row = j;
//					start.col = k;
//				}
//				else if (input[k] == '@') {
//					end.row = j;
//					end.col = k;
//				}
//			}
//		}
//		int ctr = 0;
//		q.push(start);
//		bool flag = true;
//		bool flag1 = true;
//		arr[start.row][start.col] = '0';
//		int count = q.size();
//		while (!q.empty()) {
//			if (--count == 0) {//ignore the root
//				if (flag == true) {
//					count++;
//					flag = false;
//				}
//				else {
//					ctr++;
//					count = q.size();
//				}
//			}
//			index temp = q.front();
//			q.pop();
//			if (temp.row == end.row && temp.col == end.col) {
//				flag1 = false;
//				break;
//			}
//			int row;
//			int col;
//			int flag = 0;
//			row = temp.row - 2;
//			col = temp.col - 1;
//			flag = check(row, col);
//			if (flag == 1) {
//				ctr++;
//				flag1 = false;
//				break;
//			}
//
//			row = temp.row - 1;
//			col = temp.col - 2;
//			check(row, col);
//			flag = check(row, col);
//			if (flag == 1) {
//				ctr++;
//				flag1 = false;
//				break;
//			}
//
//			row = temp.row + 2;
//			col = temp.col + 1;
//			check(row, col);
//			flag = check(row, col);
//			if (flag == 1) {
//				ctr++;
//				flag1 = false;
//				break;
//			}
//
//			row = temp.row + 1;
//			col = temp.col + 2;
//			check(row, col);
//			flag = check(row, col);
//			if (flag == 1) {
//				ctr++;
//				flag1 = false;
//				break;
//			}
//
//			row = temp.row + 2;
//			col = temp.col - 1;
//			check(row, col);
//			flag = check(row, col);
//			if (flag == 1) {
//				ctr++;
//				flag1 = false;
//				break;
//			}
//
//			row = temp.row + 1;
//			col = temp.col - 2;
//			check(row, col);
//			flag = check(row, col);
//			if (flag == 1) {
//				ctr++;
//				flag1 = false;
//				break;
//			}
//
//			row = temp.row - 2;
//			col = temp.col + 1;
//			check(row, col);
//			flag = check(row, col);
//			if (flag == 1) {
//				ctr++;
//				flag1 = false;
//				break;
//			}
//
//			row = temp.row - 1;
//			col = temp.col + 2;
//			check(row, col);
//			flag = check(row, col);
//			if (flag == 1) {
//				ctr++;
//				flag1 = false;
//				break;
//			}
//			if (count == 0) {
//				count = q.size();
//			}	
//		}
//		cout << "Case " << i << ": ";
//		if (flag1) {
//			cout << "IMPOSSIBLE" << endl;
//		}
//		else
//			cout << ctr << endl;
//	}
//	return 0;
//}