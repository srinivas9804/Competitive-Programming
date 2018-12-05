#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char word[101];
	char largest[101];
	int length = 0;
	cin >> word;
	while (strcmp(word,"E-N-D")) {
		int l = 0;
		for (int i = 0; word[i] != '\0'; i++) {
			if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || word[i] == '-')
				l++;
			if (word[i] >= 'A' && word[i] <= 'Z')
				word[i] += 'a' - 'A';
			
		}
		//cout << word << " " << endl;
		if (l > length) {
			strcpy(largest, word);
			length = l;
		}
		cin >> word;
	}
	for (int i = 0; largest[i] != '\0'; i++) {
		if ((largest[i] >= 'a'&&largest[i] <= 'z')||largest[i]=='-')
			cout << largest[i];
	}
	cout << endl;
	return 0;
}