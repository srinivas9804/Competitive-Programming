#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
	int n;
	float* dp[101];//Max number of elements
	while (cin >> n) {
		if (n == 0)
			break;
		string output="";
		float *arr = new float[n];
		int max_weight = 0;
		float sum = 0.0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		max_weight = (int)rint((sum) / 2);
		for (int i = 0; i <= n; i++) {
			dp[i] = new float[max_weight+1];
		}
		for (int i = 0; i <= n; i++) {
			for (int w = 0; w <= max_weight; w++) {
				if (i == 0 || w == 0)
					dp[i][w] = 0;
				else if (arr[i - 1] <= w) {
					if (arr[i - 1] + dp[i-1][(int)(w - arr[i - 1])] > dp[i - 1][w])
						dp[i][w] = arr[i - 1] + dp[i-1][(int)(w - arr[i - 1])];
					else
						dp[i][w] = dp[i - 1][w];
				}
				else {
					dp[i][w] = dp[i - 1][w];
				}
			}
		}
		int i = n;
		int line = max_weight;
		while (i > 0) {
			if (dp[i][line] - dp[i - 1][(int)(line - arr[i-1])] == arr[i-1]) {
				if (output == "")
					output = to_string(i);
				else
					output = to_string(i) +" "+ output;
				line = (int)rint(line - arr[i - 1]);
				i = i - 1;
			}
			else
				i = i - 1;
		}
		cout << output << endl;
	}
	return 0;
}