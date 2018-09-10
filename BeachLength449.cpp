//#include <iostream>
//#include <cstring>
//using namespace std;
//char str[200][200] = {'\0'};
//int compareRow(int j, int end){
//	int ctr = 0;
//	for (int i = 0; i < end-1; i++) {
//		if ((str[j][i] == '.'&&str[j][i + 1] == '#') || (str[j][i] == '#'&&str[j][i + 1] == '.'))
//			ctr++;
//	}
//	return ctr;
//}
//int compareBottomRow(int j, int end , int type) {// type is dependant on the hexagonal pattern. if type is 0 the row on the bottm isi shifted to the right
//	int ctr = 0;
//	if (type == 0) {
//		for (int i = 0; i < end; i++) {
//			if (i == 0) {
//				if ((str[j][i] == '.'&&str[j + 1][i] == '#') || (str[j][i] == '#'&&str[j + 1][i] == '.'))
//					ctr++;
//			}
//			else {
//				if ((str[j][i] == '.'&&str[j + 1][i] == '#') || (str[j][i] == '#'&&str[j + 1][i] == '.'))
//					ctr++;
//				if ((str[j][i] == '.'&&str[j + 1][i - 1] == '#') || (str[j][i] == '#'&&str[j + 1][i - 1] == '.'))
//					ctr++;
//			}
//		}
//	}
//	else if (type == 1) {
//		for (int i = 0; i < end; i++) {
//			if (i == end - 1) {
//				if ((str[j][i] == '.'&&str[j + 1][i] == '#') || (str[j][i] == '#'&&str[j + 1][i] == '.'))
//					ctr++;
//			}
//			else {
//				if ((str[j][i] == '.'&&str[j + 1][i] == '#') || (str[j][i] == '#'&&str[j + 1][i] == '.'))
//					ctr++;
//				if ((str[j][i] == '.'&&str[j + 1][i + 1] == '#') || (str[j][i] == '#'&&str[j + 1][i + 1] == '.'))
//					ctr++;
//			}
//		}
//	}
//	return ctr;
//}
//int main() {
//	
//	int i = 0;
//
//	while (cin.getline(str[i], 51)) {
//		int sum = 0;
//		if (str[i][0] == '\0') {
//			for (int j = 0; j < i; j++) {
//				sum += compareRow(j, strlen(str[j]));
//				if (j == 0 && i>1) {
//					sum += compareBottomRow(j, strlen(str[j]), 0);
//				}
//				else if(j!=(i-1)){
//					if (j % 2 == 0)
//						sum += compareBottomRow(j, strlen(str[j]), 0);
//					else
//						sum += compareBottomRow(j, strlen(str[j]), 1);
//				}
//			}
//			if(i>0)
//				cout << sum << endl;
//			i = 0;
//			sum = 0;
//		}
//		else
//			i++;
//	}
//	int sum = 0;
//	for (int j = 0; j < i; j++) {
//		sum += compareRow(j, strlen(str[j]));
//		if (j == 0 && i>1) {
//			sum += compareBottomRow(j, strlen(str[j]), 0);
//		}
//		else if (j != (i - 1)) {
//			if (j % 2 == 0)
//				sum += compareBottomRow(j, strlen(str[j]), 0);
//			else
//				sum += compareBottomRow(j, strlen(str[j]), 1);
//		}
//	}
//	if(i>0)
//		cout << sum << endl;
//	return 0;
//}