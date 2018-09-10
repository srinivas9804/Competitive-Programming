//#include <iostream>
//#include <string>
//using namespace std;
//
//const int ALPHABET_SIZE = 26;
//
//struct Trie {
//
//	int index;
//	Trie* child[ALPHABET_SIZE];
//	Trie()
//	{
//		for (int i = 0; i < ALPHABET_SIZE; i++)
//			child[i] = NULL;
//		index = -1;
//	}
//};
//bool insert(Trie* root, string str, int index)
//{
//	Trie* node = root;
//	for (int i = 0; i < str.size(); i++) {
//		int ind = 0;
//		ind = str[i] - 'a';
//		/* making new path if not already */
//		if (node->child[ind] == NULL) {
//			node->child[ind] = new Trie();
//		}
//
//		// go to next node
//		node = node->child[ind];
//	}
//
//	// Mark leaf (end of word) and store
//	// index of word in arr[]
//	if (node->index == -1) {// first time leaf is being added
//		node->index = index;
//		return true;
//	}
//	return false;
//}
//void preorder(Trie* node, string arr[])
//{
//	if (node == NULL)
//		return;
//
//	for (int i = 0; i < ALPHABET_SIZE; i++) {
//		if (node->child[i] != NULL) {
//
//			/* if leaf node then print key*/
//			if (node->child[i]->index != -1)
//				cout << arr[node->child[i]->index] << endl;
//
//			preorder(node->child[i], arr);
//		}
//	}
//}
//
//int main() {
//	string arr[5000];
//	string input;
//	int i = 0;
//	Trie* root = new Trie();
//	while (cin >> input) {
//		for (int k = 0; k < input.length(); k++) {
//			if ((input[k] >= 'a'&&input[k] <= 'z')) {
//				arr[i] += input[k];
//			}
//			else if ((input[k] >= 'A' && input[k] <= 'Z')) {
//				arr[i] += input[k] - 'A' + 'a';
//			}
//			else if (arr[i].length()>0) {// if there characters in the string and puntuation mark is found
//				bool flag = insert(root, arr[i], i);
//				if (flag)
//					i++;
//				else 
//					arr[i].clear();
//			}
//		}
//		bool flag = insert(root, arr[i], i);
//		if(flag)
//			i++;
//		else 
//			arr[i].clear();
//		
//	}
//	preorder(root, arr);
//	return 0;
//}