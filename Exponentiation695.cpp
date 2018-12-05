#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <algorithm>//for max function
#define MaxDigits 10000
#define PLUS 1
#define MINUS -1
using namespace std;
int position;//used to keep track of the decimal point
class bignum {
public:
	char digits[MaxDigits];
	int signbit;
	int lastdigit;
	bignum();

};
void add_bignum(bignum* a, bignum* b, bignum* c);
void subtract_bignum(bignum* a, bignum* b, bignum* c);
void zero_justify(bignum* n);
int compare_bignum(bignum *a, bignum *b);
void multiply_bignum(bignum a, bignum b, bignum* c);
void digit_shift(bignum *n, int d);

bignum::bignum() {
	fill(begin(digits), end(digits), 0);
	signbit = PLUS;
	lastdigit = -1;
}
void digit_shift(bignum *n, int d) {
	if (n->lastdigit == 0 && n->digits[0] == 0)
		return;
	for (int i = n->lastdigit; i >= 0; i--)
		n->digits[i + d] = n->digits[i];
	for (int i = 0; i < d; i++)
		n->digits[i] = 0;
	n->lastdigit += d;
}
void multiply_bignum(bignum a, bignum b, bignum* c) {
	bignum row;
	bignum tmp;
	*c = bignum();
	row = a;
	for (int i = 0; i <= b.lastdigit; i++) {
		for (int j = 1; j <= b.digits[i]; j++) {
			add_bignum(c, &row, &tmp);
			*c = tmp;
		}
		digit_shift(&row, 1);
	}
	c->signbit = a.signbit * b.signbit;
	zero_justify(c);
}
void multiply(bignum a, bignum b, bignum* c) {
	int result[10000];
	memset(result, 0, sizeof(result));
	for (int i = 0; i <= b.lastdigit; i++) {
		for (int j = 0; j <= a.lastdigit; j++) {
			result[i + j ] += b.digits[i] * a.digits[j];
		}
	}
	int carry = 0;
	for (int i = 0; i <= a.lastdigit+b.lastdigit; i++) {
		int temp = result[i] + carry;
		result[i] = temp % 10;
		carry = temp / 10;
	}
	result[a.lastdigit+b.lastdigit+1] = carry;
	*c = bignum();
	for (int i = 0; i <= a.lastdigit + b.lastdigit+1; i++) {
		c->digits[++c->lastdigit] = result[i];
	}
	c->signbit = a.signbit * b.signbit;
	zero_justify(c);
}
void add_bignum(bignum* a, bignum* b, bignum* c) {
	int carry;
	int i;
	*c = bignum();// initalize c
	if (a->signbit == b->signbit)
		c->signbit = a->signbit;
	else {
		if (a->signbit == MINUS) {
			a->signbit = PLUS;
			subtract_bignum(b, a, c);
			a->signbit = MINUS;
		}
		else {
			b->signbit = PLUS;
			subtract_bignum(a, b, c);
			b->signbit = MINUS;
		}
		return;
	}
	c->lastdigit = max(a->lastdigit, b->lastdigit) + 1;
	carry = 0;
	for (i = 0; i <= (c->lastdigit); i++) {
		c->digits[i] = (char)((carry + a->digits[i] + b->digits[i]) % 10);
		carry = (carry + a->digits[i] + b->digits[i]) / 10;
	}
	zero_justify(c);
}
void zero_justify(bignum* n) {
	while (n->lastdigit > 0 && n->digits[n->lastdigit] == 0)
		n->lastdigit--;
	if (n->lastdigit == 0 && n->digits[0] == 0)
		n->signbit = PLUS;// to avoid negative zero
}
void subtract_bignum(bignum* a, bignum* b, bignum* c) {
	int borrow;
	int v;//placeholder
	if (a->signbit == MINUS || b->signbit == MINUS) {
		b->signbit = -1 * b->signbit;
		add_bignum(a, b, c);
		b->signbit = -1 * b->signbit;
		return;
	}
	if (compare_bignum(a, b) == PLUS) {
		subtract_bignum(b, a, c);
		c->signbit = MINUS;
		return;
	}
	c->lastdigit = max(a->lastdigit, b->lastdigit);
	borrow = 0;
	for (int i = 0; i <= c->lastdigit; i++) {
		v = a->digits[i] - borrow - b->digits[i];
		if (a->digits[i] > 0)
			borrow = 0;
		if (v < 0) {
			v = v + 10;
			borrow = 1;
		}
		c->digits[i] = (char)v % 10;
	}
	zero_justify(c);
}
int compare_bignum(bignum *a, bignum *b) {
	if (a->signbit == MINUS && b->signbit == PLUS)
		return PLUS;
	if (a->signbit == PLUS && b->signbit == MINUS)
		return MINUS;
	if (b->lastdigit > a->lastdigit)
		return PLUS * a->signbit;
	if (a->lastdigit > b->lastdigit)
		return MINUS * a->signbit;
	for (int i = a->lastdigit; i >= 0; i--) {
		if (a->digits[i] > b->digits[i])
			return(MINUS * a->signbit);
		if (b->digits[i] > a->digits[i])
			return(PLUS * a->signbit);
	}

}
void int_to_bignum(int s, bignum *n) {
	int t;
	if (s >= 0)
		n->signbit = PLUS;
	else
		n->signbit = MINUS;
	t = abs(s);
	while (t > 0) {
		n->lastdigit++;
		n->digits[n->lastdigit] = t % 10;
		t /= 10;
	}
}
bignum Exp(bignum *a, int times) {
	if (times == 1)
		return *a;
	if (times == 0) {
		int_to_bignum(1, a);
		return *a;
	}
	bignum tmp = Exp(a, times >> 1);
	multiply(tmp, tmp, &tmp);
	if (times & 1) {
		multiply(tmp, *a, &tmp);
	}
	return tmp;
}
int num_start(bignum* n) {//returns the index of the first non_zero element
	int index = -1;
	for (int i = 0; i <= n->lastdigit; i++) {
		if (n->digits[i] != 0)
			return i;
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	while (cin >> input) {
		position = -1;
		int power;
		cin >> power;
		bignum num;

		for (int i = input.length() - 1; i >= 0; i--) {
			if (input[i] == '.')
				position = num.lastdigit + 1;
			else
				num.digits[++num.lastdigit] = input[i] - '0';
		}
		bignum exp = Exp(&num, power);
		position = position * power;
		int start = num_start(&exp);
		zero_justify(&exp);
		if (position < 0)
			position = 0;

		for (int i = exp.lastdigit; i >= position && i >= start; i--) {
			cout << (int)exp.digits[i];
		}
		if (position>0 && position > start) {
			cout << ".";	
			for (int i = position - 1; i >= 0 && i >= start; i--) {
				cout << (int)exp.digits[i];
			}
		}
		cout << endl;
	}
	return 0;
}