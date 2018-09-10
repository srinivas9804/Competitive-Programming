//#include <iostream>
//#include <cstring>
//#include <stack>
//#include <iomanip>
//using namespace std;
//
//int main() {
//	char str[101];
//	while (cin >> str) {
//		char postfix[101];
//		stack <int>result;
//		int sum;
//		int j = 0;
//		stack <char>s;
//		for (int i = 0; str[i] != '\0'; i++) {
//			if (str[i] == ' ')
//				continue;
//			if ((str[i] >= '0'&&str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F')) {
//				postfix[j++] = str[i];
//			}
//			else if (str[i] == '+' || str[i] == '*') {
//				if (s.empty()){//stack is empty	
//					s.push(str[i]);
//				}
//				else {
//					char c;
//					if (!s.empty())
//						c = s.top();
//					if ((c == '+'&&str[i] == '*') || (c != '*' && str[i] == '+')|| (str[i] == '*')) {//higher precedence 
//						s.push(str[i]);
//					}
//					else{
//						postfix[j++] = c;
//						if (!s.empty())
//						s.pop();
//						i--;//Check character again
//					}
//
//				}
//
//			}
//			else if (str[i] == '(')
//				s.push(str[i]);
//			else if (str[i] == ')') {
//				char c;
//				if (!s.empty())
//				while ((c = s.top()) != '(') {
//					postfix[j++] = c;
//					if (!s.empty())
//					s.pop();
//				}
//				if(!s.empty())
//				s.pop();	
//			}
//		}
//		while (!s.empty()) {
//			char c = s.top();
//			s.pop();
//			postfix[j++] = c;
//		}
//		postfix[j++] = '\0';
//		for (int i = 0; postfix[i] != '\0'; i++) {
//			if ((postfix[i] >= '0'&&postfix[i] <= '9')) {
//				result.push(postfix[i]-'0');
//			}
//			else if (postfix[i] >= 'A' && postfix[i] <= 'F') {
//				result.push(postfix[i] - 'A'+10);
//			}
//			else {
//				int n1 = 0; int n2 = 0;
//				if (!result.empty())
//				n1 = result.top();
//				if (!result.empty())
//				result.pop();
//				if (!result.empty())
//				n2 = result.top();
//				if (!result.empty())
//				result.pop();
//				if (postfix[i] == '+') {
//					sum = n1 + n2;
//					result.push(sum);
//				}
//				else {
//					sum = n1 * n2;
//					result.push(sum);
//				}
//			}
//		}
//		int d = 0;
//		if (!result.empty())
//		d = result.top();
//		cout <<setiosflags(ios_base::uppercase)<< hex << d<<endl;
//	}
//	return 0;
//}