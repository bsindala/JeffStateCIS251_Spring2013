#include <iostream>
using namespace std;

double totalCost(int quantity, double unitPrice); // function prototype

int main()
{
	double priceEach, bill;
	int units;

	cout << "Enter the number of units purchased: ";
	cin >> units;
	cout << "Enter the price per unit: ";
	cin >> priceEach;

	bill = totalCost(units, priceEach); // function call

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Final bill with tax is $" << bill << endl;

	return 0;
}

double totalCost(int quantity, double unitPrice)
{
	const double TAX_RATE = 0.05;
	double subtotal;

	subtotal = quantity * unitPrice;
	return (subtotal + subtotal * TAX_RATE);
}