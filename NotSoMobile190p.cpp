#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int weight = 0;
int flag = 0;
int func() {
	int w1, d1, w2, d2;
	string in;
	getline(cin, in);
	if (in[0] == '\n' || in[0]=='\0') {
		flag = 1;
		return -1;
	}
	stringstream stream(in);
	stream >> w1 >> d1 >> w2 >> d2;
	if (w1 == 0) {
		w1 = func();
		if (w1 == 1) 
			w1 = weight;
		else
			return -1;
	}
	if (w2 == 0) {
		w2 = func();
		if (w2 == 1)
			w2 = weight;
		else
			return -1;
	}
	if (w1 == -1 || w2 == -1)
		return -1;
	weight = w1 + w2;
	return (w1*d1 == w2 * d2);
}
int main() {
	int ctr = 0;
	string in;
	getline(cin, in);
	stringstream input(in);
	int num = 0;
	input >> num;
	getline(cin, in);
	for (int i = 0; i < num; i++) {
		int val = 0;
		flag = 0;
		val = func();
		if (ctr == 0) {
			if (val == 1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
			ctr++;
		}
		else {
			if (val == 1)
				cout << endl << "YES" << endl;
			else
				cout << endl << "NO" << endl;
		}
		while (flag == 0) {
			getline(cin, in);
			if (in[0] == '\n' || in[0] == '\0') {
				flag = 1;
			}
		}
	}
	return 0;
}