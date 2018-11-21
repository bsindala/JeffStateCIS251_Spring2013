//Boniface Sindala
//CIS 251 (Spring 2013)
//Lab Assignment 10
//Friday, March 29, 2013
//In this assignment, I will use C++ syntax to create
//a dynamic array, populate it with values from input,
//display its values in reverse order, and delete it when finished.
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int array_size, index;
	int *values; //Declaration of the pointer values
	
	cout << "This program sorts values entered in reverse order.\n" << endl;
	cout << "How many values do you want to be sorted in reverse older: ";
	cin >> array_size;
	
	if ((array_size != 1) && (array_size <= 0)) //Loop for invalid entries
	{
		cout << "The size entered is invalid.\n"
			 << "Please enter a valid number: ";
		cin >> array_size;
		cout << endl;
		if ((array_size != 1) && (array_size <= 0))
		{
			cout << "Entered wrong size twice, program will now exit!" << endl;
			exit(1); //Exit function to exit the program after 2 wrong entries
		}
	}
	values = new int[array_size];
	for (index = 0; index < array_size; index++) //Loop for values to be sorted
	{
		cout << "Enter value#" << index + 1 << ": ";
		cin >> values[index];
	}
	cout << endl;
	cout << "Here are the values you entered in reverse order:\n";
	for (index = 0; index < array_size; index++) //Loop for reverse sorting of values
		{
			cout << "Value #" << array_size - index << ": ";
			cout << values[array_size - (index + 1)] << endl;
	}

	delete [] values; //Delete statement to free memory used by the pointer

	cout << endl;

	return 0;
}