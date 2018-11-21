#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double leg1, leg2, hypotenuse;
	cout << "Enter the length of the first leg: ";
	cin >> leg1;
	cout << "Enter the length of the second leg: ";
	cin >> leg2;
	hypotenuse = sqrt(pow(leg1, 2.0) + pow(leg2, 2.0));
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "The length of the hypotenuse is " << hypotenuse << endl;
	return 0;
}