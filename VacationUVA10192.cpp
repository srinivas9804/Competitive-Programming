#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int mat[101][101];
int main() {
	int ctr = 1;
	string str1;
	string str2;
	while (getline(cin, str1)) {
		if (str1[0] == '#')
			return 0;
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
						mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
					}
				}
			}
		}
		cout << "Case #"<<ctr++<<": you can visit at most "<<mat[n][m]<<" cities." << endl;
	}
	return 0;
}