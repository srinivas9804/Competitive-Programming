//// Student name: SIVAKUMAR Srinivas
//// Student ID  : 54486977
//
///*
//Submission deadline: Sunday, 28 Jan 2018, 11:59pm
//
//Upload your .cpp file to Canvas.
//Put down your name and student ID at the top of your file.
//
//10% Marks will be deducted for
//- Submission without name and ID
//- Submission of other file type
//
//Late submission or submission by other means (e.g. email) are not accepted.
//*/
//
//#include <iostream>
//#include <iomanip>
//#include <cstdlib>
//
//using namespace std;
//
//// Part-1:	convert letter grade to grade point
//double toGradePoint(const char *letterGrade)
//{
//	// Precondition: input letterGrade is a valid grade used in CityU
//	// Grade points are based on the definitions used in CityU
//
//	double gp = 0;
//	if (letterGrade[0] == 'A')
//		gp = 4.0;
//	else if (letterGrade[0] == 'B')
//		gp = 3.0;
//	else if (letterGrade[0] == 'C')
//		gp = 2.0;
//	else if (letterGrade[0] == 'D')
//		gp = 1.0;
//	else if (letterGrade[0] == 'F')
//		gp = 0.0;
//	if (letterGrade[1] == '+')
//		gp += .3;
//	else if (letterGrade[1] == '-')
//		gp -= .3;
//
//
//
//
//	// Your codes
//
//	return gp;
//}
//
//// Part-2: case sensitive string matching
//int search(const char *key, const char *text, int start)
//{
//	// Search for the key from the start position in text[]
//	// If the key is found, return the position of the first matching substring,
//	// i.e. the position of the first char of the matching substring in text[]
//
//	int i = start;
//	int index = 0;
//	int length = 0;
//	int j = 0;
//
//
//	while (text[i] != '\0')  // not end of string
//	{
//		if (text[i] == key[index]) {
//			index++;
//			if (key[index] == '\0') {
//				return start;
//			}
//		}
//		else {
//			index = 0;
//			i = start++;
//		}
//		i++;
//		// Write your own codes. DO NOT use any C library function in your implementation.
//
//	}
//	return -1;  // not found
//}
//
//// part-3: case insensitive string matching
//int searchCaseInsensitive(const char *key, const char *text, int start)
//{
//
//	// Write your own codes. DO NOT use any C library function in your implementation.
//	int i = start;
//	int index = 0;
//	int length = 0;
//	int value = 0;
//	int j = 0;
//
//	while (text[i] != '\0')  // not end of string
//	{
//		if (text[i] >= 'a'&&text[i] <= 'z')
//			value = -32;
//		else if (text[i] >= 'A'&&text[i] <= 'Z')
//			value = 32;
//		if (text[i] == key[index] || (text[i] + value) == key[index]) {
//			index++;
//			if (key[index] == '\0') {
//				return start;
//			}
//		}
//		else {
//			index = 0;
//			i = start++;
//		}
//
//		i++;
//		// Write your own codes. DO NOT use any C library function in your implementation.
//
//	}
//	return -1;  // not found
//}
//
//
//// -------------------------------- main() function is prepared for you
//int main()
//{
//	// Part-1
//	cout << "Part-1: convert letter grade to grade point" << endl << endl;
//
//	 const char *letterGrades[] = { "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F" };
//
//	for (int i = 10; i >= 0; i--)
//	{
//		cout << "Letter grade " << setw(2) << std::left << letterGrades[i] << " : grade point = "
//			<< toGradePoint(letterGrades[i]) << endl;
//	}
//
//	// Part-2
//	cout << "\n-----------------------------------------------------\n";
//	cout << "Part-2: string matching (case sensitive)\n\n";
//
//	 const char text1[] = "Test data stream : EE2331 Data Structures and Algorithms Tutorial-1";
//	const char *key[] = { "data", "stream", "algorithm" };
//
//	// With case sensitive search, the key "data" is found at location 5
//
//	for (int i = 0; i < 3; i++)
//	{
//		cout << "Searching for \"" << key[i] << "\"" << endl;
//		int count = 0;
//		int loc = -1;
//		do
//		{
//			loc = search(key[i], text1, loc + 1);
//			if (loc >= 0)
//			{
//				cout << "  Find \"" << key[i] << "\" at location " << loc << endl;
//				count++;
//			}
//		} while (loc >= 0);
//
//
//		if (count == 0)
//			cout << "  Not found\n";
//		cout << endl;
//	}
//
//	// Part-3
//	cout << "-----------------------------------------------------\n";
//	cout << "Part-3: string matching (case insensitive)\n\n";
//
//	// With case insensitive search, the key "data" is found at locations 5 and 26
//
//	for (int i = 0; i < 3; i++)
//	{
//		cout << "Searching for \"" << key[i] << "\" (case insensitive)" << endl;
//		int loc = -1;
//		int count = 0;
//		do
//		{
//			loc = searchCaseInsensitive(key[i], text1, loc + 1);
//			if (loc >= 0)
//			{
//				cout << "  Find \"" << key[i] << "\" at location " << loc << endl;
//				count++;
//			}
//		} while (loc >= 0);
//
//		if (count == 0)
//			cout << "  Not found\n";
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}