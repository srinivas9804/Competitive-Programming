#include <iostream>
#include <string>
using namespace std;
void kmp(string pat, string text, int* lps) {//returns the index at which pattern is found
	int m = pat.length();
	int n = text.length();
	bool found = false;
	int i = 0;
	int j = 0;
	while (i < n) {
		if (pat[j] == text[i]) {
			i++; 
			j++;
		}
		if (j == m) {
			j = lps[j - 1];
			found = true;
		}
		else if (i<n && pat[j]!=text[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	cout << text;
	if (!found) {
		for (int k = j; k < pat.length(); k++)
			cout << pat[k];
	}
	cout << endl;
}
void computeFailureFunction(string pat, int n, int* lps) {
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < n) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i++] = len;
		}
		else {
			if (len != 0) {
				len = lps[len - 1];
			}
			else {
				lps[i++] = 0;
			}
		}
	}
}
int main() {
	int f[100001];
	string input;
	while (cin >> input) {
		string revstr = "";
		for (int i = input.length()-1; i >= 0; i--) {
			revstr += (char)input[i];
		}
		computeFailureFunction(revstr, revstr.length(), f);
		kmp(revstr, input, f);
	}
	return 0;
}