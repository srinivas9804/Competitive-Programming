///*
//* Student name:SIVAKUMAR Srinivas
//* Student ID  :54486977
//*
//* EE2331 Data Structures and Algorithms 2017/18 Sem B
//*
//* Submission deadline: Sunday, 25 March 2018, 11:59 pm.
//*
//* You are asked to implement the two functions specified below:
//*      infix2postfix()
//*      postfix2infix()
//*
//* Each function does a conversion from one mathematical notion to another one.
//* You should use C++ STL built-in stack and string class.
//*
//* Some test cases are provided for you in the input file. However, they are not
//* meant to be exhaustive and you are responsible to verify if your code fulfills
//* the requirements.
//*
//*/
//
//#include <cstdlib>
//#include <cstdio>
//#include <iostream>
//#include <fstream>
//#include <stack>
//#include <string>
//
//
//using namespace std;
//
//bool isHigherPrecedence(char op1, char op2);
//bool isOperator(char c);
//
////-------------------------- functions to be implemented by you
//
///*
//* Convert an infix expression to a postfix expression, where both are represented
//* as a C++ string object. Return the converted postfix string.
//*
//* Precondition:
//* - all operands are single-character long.
//* - the infix expression may contain +, -, *, /, ( and ) these 6 operators.
//*/
//string infix2postfix(string infix) {
//	string postfix="";
//	int j = 0;
//	stack <char>s;
//	for (int i = 0; i < (int)infix.length(); i++) {//type casting to int because length returns unsigned int
//		if (isOperator(infix[i])) {
//			if (s.empty()) {//stack is empty	
//				s.push(infix[i]);
//			}
//			else {
//				char c = s.top();
//				if ((!isOperator(c))||isHigherPrecedence(infix[i], c)) {
//					s.push(infix[i]);
//				}
//				else {
//					postfix += c;
//					s.pop();
//					i--;//check character again
//				}
//			}
//		}
//		else if (infix[i] == '(')
//			s.push(infix[i]);
//		else if(infix[i] == ')'){
//			char c;
//			if (!s.empty()) {
//				while ((c = s.top()) != '(') {
//					postfix += c;
//					if (!s.empty())
//						s.pop();
//				}
//			}
//		}
//		else {
//			postfix += infix[i];
//		}
//	}
//	while (!s.empty()) {
//		char c = s.top();
//		s.pop();
//		if(isOperator(c))
//			postfix += c;
//	}
//
//	return postfix;
//
//}
//
//
///*
//* Convert a postfix expression to a "fully parenthesized" infix expression, where both are represented
//* as a C++ string object. Return the converted infix string.
//*
//* Precondition:
//* - all operands are single-character long.
//* - the postfix expression may contain +, -, * and / these 4 operators.
//*/
//string postfix2infix(string postfix) {
//	stack <string>s;
//	for (int i = 0; i < (int)postfix.length(); i++) {
//		if (!isOperator(postfix[i])) {
//			string temp;
//			temp+=postfix[i];
//			s.push(temp);
//		}
//		else {
//			string temp;
//			temp = '(';//adding a opening parenthesis to the begining of the string
//			string op1 = s.top();
//			s.pop();
//			string op2 = s.top();
//			s.pop();
//			temp += op2;
//			temp += postfix[i];
//			temp += op1;
//			temp += ')';
//			s.push(temp);
//		}
//	}
//	return s.top();
//
//}
//
//
////-------------------------- functions prepared for you
//
//bool isOperator(char c) {
//	if (c == '+' || c == '-' || c == '*' || c == '/') //  you may add operator here
//		return true;
//	return false;
//}
//
///*
//* Compare precedence of +, -, *, / and return true if op1 has higher
//* precedence than op2. Otherwise return false.
//*/
//bool isHigherPrecedence(char op1, char op2) {
//	if (op1 == '+' || op1 == '-')
//		return false;
//	else if (op2 == '+' || op2 == '-')
//		return true;
//	else
//		return false;
//}
//
///*
//* ****************************
//* NO MODIFICATION IS NEEDED
//* ****************************
//* Driver program
//*
//* Read the test cases from the input file and use them as the input to test
//* your function implementation.
//*
//*/
//int main(int argc, char** argv) {
//
//	ifstream fin("t8_input.txt");
//	if (!fin) {
//		cout << "Input file not found." << endl;
//		system("pause");
//		exit(1);
//	}
//
//	int testcase = 0;
//	fin >> testcase;
//
//	string infix;
//	string postfix;
//	for (int i = 1; i <= testcase; i++) {
//
//		fin >> infix;
//		cout << "Case " << i << endl;
//		cout << "Original Infix expression: " << infix << endl;
//		postfix = infix2postfix(infix);
//		cout << "From Infix to Postfix: " << postfix << endl;
//		infix = postfix2infix(postfix);
//		cout << "From Postfix to Infix: " << infix << endl;
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}
//
