#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <math.h>
//#include <fstream>
using namespace std;

const int len = 100000000;
int arr[(len >> 6) + 1];
#define IsPrime(n) (arr[n>>6]&(1<<((n>>1)&31)))
#define SetPrime(n) (arr[n>>6]|=(1<<((n>>1)&31)))
void primes() {

	for (int i =3; i*i <= len; i+=2)//only check odd numbers
	{
		// If arr[p] is not changed, then it is a prime
		if (!IsPrime(i))
		{
			// Update all multiples of i
			for (int j = i*i ; j <= len; j += 2*i) {
				SetPrime(j);
			}
		}
	}
}
bool check(int n) {
	
	if (n==2)//even
		return true;
	if ((n % 2)==0||n<2)
		return false;
	return ! IsPrime(n);
}
int main() {
	
	int n;
	memset(arr, 0, sizeof(int)*((len >> 6) + 1));
	primes();
	//ofstream myfile;
	//myfile.open("output.txt");
	while (cin>>n) {
		bool flag = false;
		int i = 0;
		if (n%2!=0) {
			if ((n - 2) > 0) {
				if (check(n - 2)) {
					i = 2;
					flag = true;
				}
			}
		}
		else {
			if ((n / 2) % 2 == 0) {
				for (i = (n / 2) - 1; i > 0; i = i - 2) {
					if (i > n - i)
						break;
					if (check(i) && check(n - i) && i!=n-i) {
						flag = true;
						break;
					}
				}
			}
			else {
				for (i = (n / 2); i >0; i = i - 2) {
					if (i > n - i)
						break;
					if (check(i) && check(n - i) && i != n - i) {
						flag = true;
						break;
					}
				}
			}
		}	
		if (flag) {
			cout << n << " is the sum of " << i << " and " << n - i << "." << endl;
			//myfile << n << " is the sum of " << i << " and " << n - i << "." << endl;
		}
		else {	
			cout << n << " is not the sum of two primes!" << endl;
			//myfile << n << " is not the sum of two primes!" << endl;
		}
	}
	return 0;
}