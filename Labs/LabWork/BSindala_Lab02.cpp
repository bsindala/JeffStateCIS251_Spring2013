// Boniface Sindala
// CIS 251 (Spring 2013)
// Laboratory Assignment 2
// Saturday, January 19, 2013
// In this assignment, I am practicing basic C++ statements such as 
// declaring variables and constants, input and output, and assignment.
// Programming is the joy of my professional life.

#include <iostream>
using namespace std;

int main()
{
	double radius, area, circumference;
	const double PI = 3.14;

	cout << "Please Enter the radius of the circle: "; // Lets the user enter in the radius of any circle of different size
	cin >> radius;

	area = PI * radius * radius;     // Calculates the area for the circle of given radius
	circumference = PI * 2 * radius; // Calculates the circumference for the circle of given radius

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "\n";

	// Displays the solution
	cout << "If a circle has a radius of " << radius << " inches, \n"; 
	cout << "it's area is " << area << " square inches.\n";
	cout << "And its circumference is ";
	cout << circumference << " inches.\n";

	cout << endl;

	return 0;
}