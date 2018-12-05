#include <iostream>
#include <string>
using namespace std;
int main() {
	int n=0;
	cin >> n;
	string str;
	for (int k = 0; k < n; k++) {
		cin >> str;
		string largest = "";
		char max = str[0];
		int index = 0;
		for (int i = 0; i < (int)str.length(); i++) {
			for (int j = i; j < (int)str.length(); j++) {
				if (str[j] > max) {
					max = str[j];
					index = j;
				}
			}
			largest += max;
			max = str[index+1];
			i = index++;
		}
		cout << largest << endl;
	}
	return 0;
}