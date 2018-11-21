#include <iostream>
using namespace std;

int main()
{
	int hours;
	double tuition;
	const double FEE_PER_HOUR = 138.00;
	cout << "Enter hours enrolled: ";
	cin >> hours;
	cout << endl; // Leave a space
	if (hours >= 12) // Fixed full time tuition nomatter the number of hours
	{
		cout << "Full-time tuition applies.\n";
		tuition = 1500.00; // Part-time classes below 12 hours
	}
	else
	{
		cout << "Part-time tuition applies.\n";
		tuition = hours * FEE_PER_HOUR;
	}
	// Formatting Statements
	cout.setf(ios::fixed); // Don't Use Scientific Notation
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "Your tuition is $" << tuition << endl;
	return 0;
}