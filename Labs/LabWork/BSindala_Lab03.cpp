// Boniface Sindala
// CIS 251 (Spring 2013)
// Laboratory Assignment 3
// Friday, January 25, 2013
// In this assignment, I am practicing how to use branching structures
// to determine the amount due from a customer at a fast food restaurant
// based on the customers menu choices.

#include <iostream>
using namespace std;

int main()
{
	int choice;
	double subtotal, tax_amount, total;
	const double SALES_TAX_RATE = 0.08;
	const double hamburger = 1.29, cheeseburger = 1.49;
	const double medium_fries = 1.59, large_fries = 1.79;
	const double small_drink = 1.59, large_drink = 1.99;

	// Welcome note and display of Entrees
	cout << "Welcome to Santino Internation Cuisine Restaurant!" << endl << endl;
	cout << "Please choose your Entree from the following: " << endl << endl;
	cout << "1. Hamburger. " << endl;
	cout << "2. Cheeseburger. " << endl;
	cout << "Make your selection now: ";
	cin >> choice;
	cout << endl << endl;

	// Choosing the Entree
	if (choice == 1)
	{
		cout << "You selected a hamburger. " << endl;
		subtotal = 1.29;
	}
	else if (choice == 2)
	{
		cout << "You selected a cheeseburger. " << endl;
		subtotal = 1.49;
	}
	cout << endl << endl;

	// Selection for Fries
	cout << "Would you like French Fries with your Entree? " << endl << endl;
	cout << "O. None. " << endl;
	cout << "1. Medium French Fries. " << endl;
	cout << "2. Large French Fries. " << endl;
	cout << "Enter your selection now: ";
	cin >> choice;
	cout << endl << endl;

	// Size of Fries
	if (choice == 0)
	{
		cout << "No French Fries with this Entree." << endl;
		subtotal = subtotal;
	}
	else if (choice == 1)
	{
		cout << "You selected a medium order of French Fries with this Entree. " << endl;
		subtotal += 1.59;
	}
	else if (choice == 2)
	{
		cout << "You selected a large order of French Fries with this Entree. " << endl;
		subtotal += 1.79;
	}
	cout << endl << endl;

	// Selection for Drinks
	cout << "Would your like a drink with your Entree? " << endl << endl;
	cout << "0. None. " << endl;
	cout << "1. Small Drink. " << endl;
	cout << "2. Large Drink. " << endl;
	cout << "Enter your selection now: ";
	cin >> choice;
	cout << endl << endl;

	// Size of Drink
	if (choice == 0)
	{
		cout << "No Drinks with this Entree." << endl;
		subtotal = subtotal;
	}
	else if (choice == 1)
	{
		cout << "You selected a Small Drink with this Entree. " << endl;
		subtotal += 1.59;
	}
	else if (choice == 2)
	{
		cout << "You selected a Large Drink with this Entree. " << endl << endl;
		subtotal += 1.99;
	}

	// Perform and Display Calculations
	tax_amount = subtotal * SALES_TAX_RATE;
	total = subtotal + tax_amount;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << endl;

	cout << "Subtotal:	$" << subtotal << endl;
	cout << "Sales Tax:	$" << tax_amount << endl;
	cout << "Total:		$" << total << endl << endl;
	return 0;
}