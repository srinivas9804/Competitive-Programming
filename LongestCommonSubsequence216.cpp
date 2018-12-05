#include <iostream>
#include <string>
using namespace std;
int mat[1001][1001];
int main() {
	string str1;
	string str2;
	while (getline(cin, str1)) {
		getline(cin, str2);
		int n = str1.length();
		int m = str2.length();
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0)
					mat[i][j] = 0;
				else if (j == 0)
					mat[i][j] = 0;
				else {
					if (str1[i - 1] == str2[j - 1]) {
						mat[i][j] = mat[i - 1][j - 1] + 1;
					}
					else {
						if (mat[i - 1][j] > mat[i][j - 1]) {
							mat[i][j] = mat[i - 1][j];
						}
						else {
							mat[i][j] = mat[i][j-1];
						}
					}	
				}
			}
		}
		cout << mat[n][m] << endl;
	}
	return 0;
}