#include <iostream>
using namespace std;

int main()
{
	int sum = 0, value;
	double average;

	cout << "Enter ten values:" << endl;

	for (int a = 1; a <= 10; a++)
	{
		cin >> value;
		sum += value;		// sum = sum + value
	}

	average = sum / 10.0;	// real number division

	cout.setf(ios::fixed);	// number formattinf
	cout.setf(ios::showpoint);
	cout.precision(1);

	cout << "Sum of the values: " << sum << endl;
	cout << "Average value:     " << average << endl;

	return 0;
}