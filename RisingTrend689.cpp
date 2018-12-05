#include <iostream>
#include <string>
using namespace std;
int arr[1000000];
int aux[1000000];
int main() {
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		fill(begin(aux), begin(aux) + n, 0);
		int l = 1;
		aux[0] = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] < aux[0])
				aux[0] = arr[i];
			else if (arr[i] >= aux[l - 1]) {
				aux[l] = arr[i];
				l++;
			}
			else {
				int start = -1;
				int end = l - 1;
				int mid;
				while (end-start >1) {
					mid = start+(end-start)/ 2;
					if (aux[mid] == arr[i]) {// add the element after the mid value
						if (aux[++mid] != arr[i]) {
							break;
						}
						else {
							while (aux[++mid] == arr[i]) {

							}
						}
						break;
					}
					else if (aux[mid + 1] > arr[i] && aux[mid] < arr[i]) {// if the element is greater than the mid but less than next element
						// it can be replaced
						mid++;
						break;
					}
					else if (aux[mid] > arr[i])
						end = mid;	
					else
						start = mid;
				}
				aux[mid] = arr[i];
			}
		}
		cout << l << endl;
	}
	return 0;
}