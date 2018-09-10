//#include <iostream>
//#include <cstring>
//#include <string>
//#include <stack>
//#include <iomanip>
//using namespace std;
//
//int main() {
//	int n = 0;
//	int ctr = 0;
//	string str;
//	getline(cin, str);
//	n = str[0] - '0';
//	getline(cin, str);
//	for (int i = 0; i < n; i++) {
//		getline(cin, str);
//		string postfix;
//		stack <char> s;
//		while (2>1) {
//			if (str[0] == '\n' || str[0]=='\0')
//				break;
//			if (str[0] >= '0'&&str[0] <= '9') {
//				postfix += str[0];
//			}
//			else if (str[0] == '+' || str[0] == '*' ||str[0] == '/' || str[0] == '-') {
//				if (s.empty()) {//stack is empty	
//					s.push(str[0]);
//				}
//				else {
//					char c;
//					if (!s.empty())
//						c = s.top();
//					if (((str[0]=='*'||str[0]=='/') && (c!='*'&& c!= '/'))||((str[0] == '+'||str[0] == '-')&&(c != '*'&& c != '/' && c!='+' && c!='-'))) {
//						s.push(str[0]);
//					}
//					else {
//						postfix += c;
//						if (!s.empty())
//							s.pop();
//						continue;//Check character again
//					}
//				}
//			}
//			else if (str[0] == '(') {
//				s.push(str[0]);
//			}
//			else if (str[0] == ')') {
//				char c;
//				if (!s.empty())
//					while ((c = s.top()) != '(') {
//						postfix += c;
//						if (!s.empty())
//							s.pop();
//					}
//				if (!s.empty())
//					s.pop();
//			}
//			getline(cin, str);
//		}
//		while (!s.empty()) {
//			char c = s.top();
//			s.pop();
//			postfix += c;
//		}
//		if (ctr == 0) {
//			cout << postfix << endl;
//			ctr++;
//		}
//		else
//			cout << endl << postfix << endl;
//	}
//	return 0;
//}