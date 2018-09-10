//#include <iostream>
//#include <string>
//#include <cstdlib>
//using namespace std;
//int compare(const void* a, const void* b) {
//	string *str1 = (string *)a;
//	string *str2 = (string *)b;
//	return (*str1).compare(*str2);
//}
//string arr[2000000];
//int main() {
//	int n;
//	while (cin >> n) {
//		string input;
//		char output[8] = { 0 };
//		output[7] = '\0';
//		getline(cin, input);
//		for (int i = 0; i < 2 * n - 1; i++) {
//			getline(cin, arr[i]);
//			/*for (int j = 0; j < 7; j++) {
//				output[j] = output[j] ^ input[j];
//			}*/
//		}
//		bool flag = true;
//		qsort(arr, 2 * n - 1, sizeof(string), compare);
//		for (int i = 0; i < 2 * n - 2; i += 2) {
//			if (arr[i] != arr[i + 1]) {
//				cout << arr[i] << endl;
//				flag = false;
//			}
//		}
//		if (flag)
//			cout << arr[2 * n - 2] << endl;
//	}
//	return 0;
//}