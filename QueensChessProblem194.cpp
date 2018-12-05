#include <iostream>
#include <iomanip>
using namespace std;
int mat[9][9] = { 0 };
int rows[9] = { 0 };
int num = 1;
int column = 0;
int sol_no = 1;
int check(int row, int col) {//check if row, col element coincides with any element
	for (int i = 1; i < 9; i++) {
			if (rows[i] != 0) {
				if (rows[i] == row)
					return 0;
				else if (i == col)
					return 0;
				else if ((i + rows[i]) == (row + col))
					return 0;
				else if ((rows[i] - i) == (row - col))
					return 0;
			}
		
	}
	return 1;
}
void find(int i) {
	int flag = 0;
	if (i == 9) {
		cout << setw(2) << sol_no++;
		cout << "      ";
		for (int j = 1; j < 8; j++) {
			cout << rows[j] << " ";
		}
		cout << rows[8]<<endl;
	}
	else {
		for (int j = 1; j < 9; j++) {//for each row
			if (rows[i] != 0) {
				find(i + 1);
				break;
			}
			int c = check(j, i);
			if (c == 1) {
				rows[i] = j;
				find(i + 1);
				rows[i] = 0;
			}
		}
	}
}
int main() {

	int n = 0;
	cin >> n;
	int ctr = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 9; j++) {
			rows[j] = 0;
		}
		int row, col;
		cin >> row >> col;
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		column = col;
		rows[col] = row;
		sol_no = 1;
		find(1);
		if(i!=n)
			cout << endl;
	}
	return 0;
}	