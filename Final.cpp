//#include <iostream>
//#include <stack>
//using namespace std;
//int charCheck(char s)
//{
//	if (s>='0' && s<='9')
//		return 1;
//	else
//		return 0;
//}
//class Token
//{
//public:
//
//	virtual int eval() {
//		return 0;
//	};
//
//	virtual void printExp(int n1, char ch, int n2,int &flag) {
//    };
//	virtual ~Token() {
//
//	}
//};
//
//class Operator : public Token
//{
//public:
//    Operator(){
//    }
//    virtual void printExp(int n1, char ch, int n2,int &flag) {
//	}
//
//};
//
//class Operand : public Token
//{
//	int op;
//public:
//	Operand() {
//		op = -1;
//	}
//	Operand(int n)
//	{
//		op = n;
//	}
//	virtual int eval()
//	{
//		return op;
//	}
//
//	virtual void printExp(int n1, char ch, int n2,int &flag) {
//	}
//
//};
//
//class Binary : public Operator
//{
//public:
//    Operand op1;
//    Operand op2;
//};
//
//class Plus : public Binary
//{
//
//public:
//
//	Plus() {
//	}
//
//	Plus(Token* o1, Token* o2)
//	{
//		op1 = Operand(o1->eval());
//		op2 = Operand(o2->eval());
//	}
//
//	virtual int eval()
//	{
//		int val1 = op1.eval();
//		int val2 = op2.eval();
//		return val1 + val2;
//	}
//	~Plus() {
//		delete &op1;
//		delete &op2;
//	}
//	virtual void printExp(int n1, char ch, int n2,int &flag) {
//	if (!flag)
//		cout <<""<<n2<<" "<<ch<<" "<< n1 <<" ";
//	else
//		cout <<ch<<" "<<n2<<"";
//	flag++;
//    }
//};
//
//class Minus : public Binary
//{
//
//public:
//
//    Minus(){
//    }
//
//	Minus(Token* o1, Token* o2)
//	{
//		op1 = Operand(o1->eval());
//		op2 = Operand(o2->eval());
//	}
//
//	virtual int eval()
//	{
//		int val1 = op1.eval();
//		int val2 = op2.eval();
//		return val1 - val2;
//	}
//
//	virtual void printExp(int n1, char ch, int n2,int &flag) {
//	if (!flag)
//		cout <<""<<n2<<" "<<ch<<" "<< n1 <<" ";
//	else
//		cout <<ch<<" "<<n2<<"";
//	flag++;
//    }
//	~Minus() {
//		delete &op1;
//		delete &op2;
//	}
//};
//
//class Multiply : public Binary
//{
//
//public:
//
//    Multiply()  {
//    }
//
//	Multiply(Token* o1, Token* o2)
//	{
//		op1 = Operand(o1->eval());
//		op2 = Operand(o2->eval());
//	}
//
//	virtual int eval()
//	{
//		int val1 = op1.eval();
//		int val2 = op2.eval();
//		return val1 * val2;
//	}
//
//	virtual void printExp(int n1, char ch, int n2,int &flag) {
//	if (!flag)
//		cout <<""<<n2<<" "<<ch<<" "<< n1 <<" ";
//	else
//		cout <<ch<<" "<<n2<<"";
//	flag++;
//    }
//	~Multiply() {
//		delete &op1;
//		delete &op2;
//	}
//};
//
//class Divide : public Binary
//{
//
//public:
//
//    Divide() {
//    }
//
//	Divide(Token* o1, Token* o2)
//	{
//		op1 = Operand(o1->eval());
//		op2 = Operand(o2->eval());
//	}
//	virtual int eval()
//	{
//		int val1 = op1.eval();
//		int val2 = op2.eval();
//		return val1 / val2;
//	}
//
//	virtual void printExp(int n1, char ch, int n2,int &flag) {
//	if (!flag)
//		cout <<" "<<n2<<" "<<ch<<" "<< n1 <<" ";
//	else
//		cout <<ch<<" "<<n2<<" ";
//	flag++;
//    }
//	~Divide() {
//		delete &op1;
//		delete &op2;
//	}
//};
//
//int Evaluate(char arr[],int &flag)
//{
//    stack<Token*> s;
//    int position=0;
//    cout<<"\nInfix of given postfix expression is\n";
//
//    while (arr[position] != '\0')
//    {
//        if (charCheck(arr[position]) == 1)
//        {
//            Operand* op= new Operand (arr[position]-'0');//passing integer value
//            s.push(op);
//        }
//        else
//        {
//            switch (arr[position]) {
//
//            case '+': {
//                Operand op1(s.top()->eval());
//                s.pop();
//                Operand op2(s.top()->eval());
//                s.pop();
//                Plus *temp=new Plus();
//				temp->printExp(op1.eval(), '+', op2.eval(),flag);
//                Plus* plusexpr=new Plus(&op2,&op1);
//                s.push(plusexpr);
//                break;
//            }
//            case '-': {
//                Operand op1(s.top()->eval());
//                s.pop();
//                Operand op2(s.top()->eval());
//                s.pop();
//                Minus *temp=new Minus();
//				temp->printExp(op1.eval(), '-', op2.eval(),flag);
//                Minus* minusexpr=new Minus(&op2, &op1);
//				s.push(minusexpr);
//                break;
//            }
//            case '*': {
//                Operand op1(s.top()->eval());
//                s.pop();
//                Operand op2(s.top()->eval());
//				s.pop();
//                Multiply *temp=new Multiply();
//				temp->printExp(op1.eval(), '*', op2.eval(),flag);
//                Multiply* multiplyexpr=new Multiply(&op2, &op1);
//                s.push(multiplyexpr);
//                break;
//            }
//            case '/': {
//                Operand op1(s.top()->eval());
//                s.pop();
//                Operand op2(s.top()->eval());
//                s.pop();
//                Divide *temp=new Divide();
//				temp->printExp(op1.eval(), '/', op2.eval(),flag);
//                Divide* divideexpr=new Divide(&op2, &op1);
//                s.push(divideexpr);
//                break;
//            }
//          }
//        }
//        position++;
//    }
//	cout << endl;
//    cout<<"Evalulation of the postfix expression gives "<<s.top()->eval() << endl;
//    return 0;
//}
//int main() {
//    char arr[50];
//	cout << "Enter postfix expressions\n";
//	while (cin >> arr)
//	{
//		int flag = 0;
//		Evaluate(arr,flag);
//	}
//	return 0;
//}
