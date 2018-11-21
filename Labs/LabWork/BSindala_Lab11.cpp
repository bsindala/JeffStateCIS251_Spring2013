//Boniface Sindala
//CIS 251 (C++ Programming)
//Laboratory Assignment 11
//April 12, 2013
//Program to use C++ syntax to develop
//a class definition and creat objects from it.
#include <iostream>
#include <string>
using namespace std;

class StoreItem
{
private:
	string item_description;
	int item_quantity;
	double item_price;
public:
	StoreItem();
	//Initializes the store item description to undescribed
	//quantity to 0 and item pice to $10.00
	StoreItem(string description, int quantity, double price);
	//Intializes the item description to description
	//item quantity to quantity and item price to price
	void description(string new_description, int new_quantity, double new_price);
	void quantity(string new_description, int new_quantity, double new_price);
	void price(string new_description, int new_quatity, double new_price);
	string get_describe();
	int get_quantity();
	double get_price();
	void input();
	void output();
};

int main()
{
	StoreItem item1, item2("Shirt", 14, 55.00);
	cout << "Item 1 in stock:\n";
	item1.output();
	cout << endl;
	cout << "Item 2 in stock:\n";
	item2.output();
	cout << endl;

	item1 = StoreItem();
	item1.input();
	cout << endl;
	cout << "The new values in Item 1:\n";
	item1.output();
	return 0;
}

StoreItem::StoreItem() : item_description("Undescribed"), item_quantity(0), item_price(10.00)
{
	//Initialized in the header section
}

StoreItem::StoreItem(string description, int quantity, double price)
{
	if ((description <= " ") && (quantity < 0) && (price < 0))
	{
		cout << "Illegal values for the description, quantity or price." << endl;
		item_description = "Undescribed";
		item_quantity = 0;
		item_price = 10.00;
		exit(1);
	}
	else
	{
		item_description = description;
		item_quantity = quantity;
		item_price = price;
	}
}

void StoreItem::description(string new_description, int new_quantity, double new_price)//Outputs the default figures if illegal entry for description is encountered.
{
	if (new_description <= " ")
	{
		cout << "\nNo item described!" << endl;
		item_description = "Undescribed";
		item_quantity = 0;
		item_price = 10.00;
		output();
		exit(1);
	}
	else
	{
		item_description = new_description;
		item_quantity = get_quantity();
		item_price = get_price();
	}
}

void StoreItem::quantity(string new_description, int new_quantity, double new_price)//Outputs the default figures if illegal entry for quantity is encountered.
{
	if (new_quantity < 0)
	{
		cout << "\nIllegal values for the quantity!" << endl;
		item_description = "Undescribed";
		item_quantity = 0;
		item_price = 10.00;
		output();
		exit(1);
	}
	item_description = get_describe();
	item_quantity = new_quantity;
	item_price = get_price();
	
}

void StoreItem::price(string new_description, int new_quantity, double new_price)//Outputs the default figures if illegal entry for price is encountered.
{
	if (new_price < 0)
	{
		cout << "\nIllegal values for the price!" << endl;
		item_description = "Undescribed";
		item_quantity = 0;
		item_price = 10.00;
		output();
		exit(1);
	}
	else
	{
		item_description = get_describe();
		item_quantity = get_quantity();
		item_price = new_price;
	}
}

string StoreItem::get_describe()
{
	return (item_description);
}

int StoreItem::get_quantity()
{
	return (item_quantity);
}

double StoreItem::get_price()
{
	return (item_price);
}

void StoreItem::input()//Inout function for the new item
{
	string describe = "Undescribed";
	int quant = 0;
	double pric = 10.0;
	cout << "Getting more information for Item 1:\n";
	cout << "Enter the Item description: ";
	getline(cin, describe);
	cout << "How many are in stock: ";
	cin >> quant;
	cout << "What is the price for the item: $";
	cin >> pric;
	
	description(describe, quant, pric);
	quantity(describe, quant, pric);
	price(describe, quant, pric);
}

void StoreItem::output()//Output function
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "Item description:\t " << item_description << endl;
	cout << "Quantity in stock:\t " << item_quantity << endl;
	cout << "Price for the item:\t $" << item_price << endl;
}