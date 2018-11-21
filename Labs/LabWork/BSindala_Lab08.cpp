//Boniface Sindala
//CIS 251 (Spring 2013)
//Laboratory Assignment 8
//MOnday, March 11, 2013
//In this assignment, I will apply C++ syntax
//to store a set of values in an array and process
//these values in various ways during the execution of the program.
#include <iostream>
using namespace std;

void search(const int grade[], int list_size, int target);
void check();
//Function to call the searc loop and compare the grades.
int main()
{
	const int GRADE_NUMBER = 15;
	int exam_grade[GRADE_NUMBER];
	int student = 0, target = 0;
	int grade =0;
	
	cout << "Program to place the 15 student grades in the rightful letter grade.\n";
		 
	for (student = 1; student <= 15; student++) //Loop for the data entry into the array
	{
		cout << "Enter grades for student #" << student << ": ";
		cin >> exam_grade[student - 1];
	
		if ((exam_grade[student - 1] <= 100) && (exam_grade[student - 1] >= 0)) {
			cout << "Enter grades for student #" << student << ": ";
			cin >> exam_grade[student - 2];
		}
		else
		{
			cout << "Input Error! Try Again Please: ";
			cin >> exam_grade[student - 1];
		}
	}
	
	//Output
	cout << "Students who earned an A: ";
	search(exam_grade, GRADE_NUMBER, 89);
	cout << endl;
	cout << "Students who earned a B: ";			
	search(exam_grade, GRADE_NUMBER, 79);
	cout << endl;
	cout << "Students who earned a C: ";			
	search(exam_grade, GRADE_NUMBER, 69);
	cout << endl;
	cout << "Students who earned a D: ";			
	search(exam_grade, GRADE_NUMBER, 59);
	cout << endl;
	cout << "Students who earned an F: ";			
	search(exam_grade, GRADE_NUMBER, 0);
	cout << endl;
	return 0;
}

void search(const int grade[], int list_size, int target) //Fumction definition
{
	int index = 0;
	for (int i = 0; i  < list_size; i++) {
		if (target == 89) {
			if (grade[i] > target)
				cout << i + 1 << " ";
		}
		if (target == 79){
			if ((grade[i] > target) && (grade[i] < 90))
				cout << i + 1 << " ";
		}
		if (target == 69){
			if ((grade[i] > target) && (grade[i] < 80))
				cout << i + 1 << " ";
		}
		if (target == 59){
			if ((grade[i] > target) && (grade[i] < 70))
				cout << i + 1 << " ";
		}
		if (target == 0){
			if ((grade[i] > target) && (grade[i] < 60))
				cout << i + 1 << " ";
		}
	}
}