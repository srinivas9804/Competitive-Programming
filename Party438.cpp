#include <iostream>
using namespace std;
//Think of the problem as a graph. If only one person has to be removed who has t friends,
//the remaining n-1 people have to have less than t-1 friends after his removal. This isn't possible,
//because only one edge will be removed. So the minimum number of people that have to be reduced is 2
int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		cin >> n;
		if (n == 1)
			cout << '0' << endl;
		else
			cout << (n - 2) << endl;
	}
	return 0;
}