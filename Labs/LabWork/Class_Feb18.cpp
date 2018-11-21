#include <iostream>
using namespace std;

void addOneScore(double&, int&);


int main()
{
	double gradeSum = 0.0;
	int gradeCount = 0;

	for (int i = 1; i <= 10; i++)
		addOneScore(gradeSum, gradeCount);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "Number of grades entered; " << gradeCount << endl;
	cout << "Sum of grades entered: " << gradeSum << endl;
	cout << "Average of grades entered: " << gradeSum / gradeCount << endl;

	return 0;
}

void addOneScore(double& sum, int& count)
{
	double newScore;

	count++;
	cout << "Enter score #" << count << ": ";
	cin >> newScore;
	sum += newScore;
}