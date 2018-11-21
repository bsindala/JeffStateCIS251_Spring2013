// Boniface Sindala
// CIS 251 (Spring 2013)
// Laboratory Assignment 4
// Friday, February 1, 2013
// In this assignment, I will learn how to use statements
// to obtain the revenue and expenses
// for a company to determine its annual profit or loss.

#include <iostream>
using namespace std;

int main()
{
	int counter = 1;
	double month_revenue, revenue_sum = 0, expenses, 
		year_expenses = 0, profit_loss;

	// Company Revenue
	cout << "Company Profit / Loss Calculator.\n" << endl;
	cout << "Revenue: \n" << endl;
	cout << "Please enter revenue for month 1:  ";
	cin >> month_revenue;
	cout << "Please enter revenue for month 2:  ";
	cin >> month_revenue;
	cout << "Please enter revenue for month 3:  ";
	cin >> month_revenue;
	cout << "Please enter revenue for month 4:  ";
	cin >> month_revenue;
	cout << "Please enter revenue for month 5:  ";
	cin >> month_revenue;
	cout << "Please enter revenue for month 6:  ";
	cin >> month_revenue;
	cout << "Please enter revenue for month 7:  ";
	cin >> month_revenue;
	cout << "Please enter revenue for month 8:  ";
	cin >> month_revenue;
	cout << "Please enter revenue for month 9:  ";
	cin >> month_revenue;
	cout << "Please enter revenue for month 10: ";
	cin >> month_revenue;
	cout << "Please enter revenue for month 11: ";
	cin >> month_revenue;
	cout << "Please entet revenue for month 12: ";
	cin >> month_revenue;

	for (counter = 1; counter <= 12; counter++)
	{
		revenue_sum += month_revenue; // Sum of the years revenue
	}

	cout << endl;
	cout << "Expenses: \n" << endl;
	cout << "Please enter the expenses: " << endl;
	cout << "After each expense, please press return to enter another one. " << endl;
	cout << "Please enter a negative number when done: " << endl;

	cin >> expenses;
	// Total Expenses
	while (expenses >= 0)
	{
		year_expenses += expenses;
		cin >> expenses;
	}

	profit_loss = revenue_sum - year_expenses;

	// Display formatting
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// Profit / Loss Display Calculations
	if (profit_loss > 0)
	{
		cout << "Your profit for the year is: $" << profit_loss << endl;
	}
	else if (profit_loss < 0)
	{
		cout << "Your loss for the year is: $" << -profit_loss << endl;
	}
	else if (profit_loss == 0)
	{
		cout << "You broke even this year. \n" << endl;
	}
	return 0;
}