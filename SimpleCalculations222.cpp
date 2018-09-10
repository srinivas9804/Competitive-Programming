//#include <iostream>
//#include <iomanip>
//#include <sstream>
//#include <string>
//using namespace std;
//int main() {
//	string input;
//	int ctr = 0;
//	while (getline(cin,input)) {
//		long double output = 0.0;
//		int flag = 0;
//		string temp;
//		for (int i = 0; i <=(int) input.length(); i++) {
//			if (input[i] == ' '||i==input.length()) {				
//				stringstream s(temp);
//				long double num = 0.0;
//				s >> num;
//				output += num;
//				temp.clear();
//			}
//			else{
//				temp+=input[i];
//			}
//		}
//		if (ctr == 0) {
//			cout << fixed << setprecision(4) << output << endl;
//			ctr++;
//		}
//		else
//			cout << endl << fixed << setprecision(4) << output << endl;
//	}
//	return 0;
//}