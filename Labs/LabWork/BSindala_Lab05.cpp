// Boniface Sindala
// CIS 251 (Spring 2013)
// Laboratory Assignment 5
// Friday, February 15, 2013
// In this assignment, I will use a function
// to calculate the discount rate to be applied 
// to and order based on the quantity of items ordered.
// I will then use the value returned by the function
// to apply the discount to the order amount, 
// which the program will then display witht the discount to the user.
#include <iostream>
using namespace std;

double getDiscountRate(int quantity, double unitPrice); // Function Prototype

int main()
{
	int Quantity;
	double pricePerItem, DiscountRate, totalBeforeDiscount, discount, total;

	cout << "Company Older Amount Calculator.\n" << endl;
	cout << "How many items does the customer want? ";
	cin >> Quantity;
	cout << endl << "How much does each item cost? $";
	cin >> pricePerItem;

	DiscountRate = getDiscountRate(Quantity, pricePerItem);// Function call

	totalBeforeDiscount = Quantity * pricePerItem;
	discount = DiscountRate;
	total = totalBeforeDiscount - discount;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << endl << "Total Before Discount: $" << totalBeforeDiscount << endl;
	cout << "Discount Amount      : $" << discount << endl;
	cout << "Total After Discount : $" << total << endl;

	return 0;
}

// Function Definition
double getDiscountRate(int quantity, double unitPrice) // Function Heading
{
	double discountRate, subtotal;
	
	// Function Body
	if (quantity <= 8)
		discountRate = 0.00;
	else if ((quantity >= 9) && (quantity <= 12))
		discountRate = 0.10;
	else if ((quantity >= 13) && (quantity <= 25))
		discountRate = 0.15;
	else if (quantity >= 26)
		discountRate = 0.20;
	
	subtotal = quantity * unitPrice;
	return (subtotal * discountRate);
}