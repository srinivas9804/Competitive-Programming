#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int ALPHABET_SIZE = 4;
struct suffix
{
	int index; // To store original index
	int rank[2]; // To store ranks and next rank pair
};
int cmp(struct suffix a, struct suffix b)
{
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) :
		(a.rank[0] < b.rank[0] ? 1 : 0);
}
int *buildSuffixArray(string txt, int n)
{
	struct suffix *suffixes = new suffix[n];	
	for (int i = 0; i < n; i++)
	{
		suffixes[i].index = i;
		suffixes[i].rank[0] = txt[i] - 'A';
		suffixes[i].rank[1] = ((i + 1) < n) ? (txt[i + 1] - 'A') : -1;
	}
	sort(suffixes, suffixes + n, cmp);

	
	int *ind= new int[n];  
	for (int k = 4; k < 2 * n; k = k * 2)
	{
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;
		
		for (int i = 1; i < n; i++)
		{
			
			if (suffixes[i].rank[0] == prev_rank &&
				suffixes[i].rank[1] == suffixes[i - 1].rank[1])
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			}
			else 
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			ind[suffixes[i].index] = i;
		}
		for (int i = 0; i < n; i++)
		{
			int nextindex = suffixes[i].index + k / 2;
			suffixes[i].rank[1] = (nextindex < n) ?
				suffixes[ind[nextindex]].rank[0] : -1;
		}
		sort(suffixes, suffixes + n, cmp);
	}
	int *suffixArr = new int[n];
	for (int i = 0; i < n; i++)
		suffixArr[i] = suffixes[i].index;
	return  suffixArr;
}
int* kasai(string text, int* suffixArr, int n) {
	int *lcp = new int[n];
	int *invSuff = new int[n];
	for (int i = 0; i < n; i++)
		invSuff[suffixArr[i]] = i;

	int k = 0;

	for (int i = 0; i<n; i++)
	{
		if (invSuff[i] == n - 1)
		{
			k = 0;
			continue;
		}
		int j = suffixArr[invSuff[i] + 1];
		while (i + k<n && j + k<n && text[i + k] == text[j + k])
			k++;
		lcp[invSuff[i]] = k; 
		if (k>0)
			k--;
	}

	// return the constructed lcp array
	return lcp;
}
int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		
		string input;
		cin >> input;
		int *suffix = buildSuffixArray(input, input.length());
		int *lcp = kasai(input, suffix, input.length());
		int max_length = 0;
		int max_index = 0;
		for (int i = 0; i < input.length() - 1; i++) {
			if (lcp[i] > max_length ) {
				max_length = lcp[i];
				max_index = i;
			}
		}
		int ctr = 1;
		for (int i = max_index; i < input.length() - 1; i++) {
			if (lcp[i] == max_length)
				ctr++;
			else
				break;
		}
		if (max_length == 0)
			cout << "No repetitions found!" << endl;
		else
			cout << input.substr(suffix[max_index],max_length) << " " << ctr << endl;
	}
	return 0;
}