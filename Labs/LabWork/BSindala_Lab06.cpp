// Boniface Sindala
// CIS 251 (Spring 2013)
// Laboratory Assignment 6
// Wednesday, February 20, 2013
// In this laboratory assignment, I am going to use the void function
// with a reference parameter and a value parameter
// to adjust one exam score for each student based on a curve.
#include <iostream> 
using namespace std;

void curveExamScore(int examScore, int curvePoints); //Function Declaration

int main()
{
	int curve_points, exam_score;

	cout << "Exam Score Curve Program.\n" << endl;
	cout << "How many points do you want to add "
		 << "to each exam? ";
	cin >> curve_points;
	cout << endl;
	cout << "Enter the first exam score (-1 to exit): ";
	cin >> exam_score;

	while (exam_score >= 0) //Function called inside loop
	{
		curveExamScore(exam_score, curve_points);
		cout << "Exam Score after Curve: " << exam_score + curve_points << endl << endl; //Curve Score Calculation and Display
		cout << "Enter another exam score (-1 to exit)  : ";
		cin >> exam_score;
	}
	cout << endl << "End of Program!" << endl << endl;
	return 0;
}

void curveExamScore(int examScore, int curvePoints) //Function Defenition
{
	examScore = examScore + curvePoints;
}