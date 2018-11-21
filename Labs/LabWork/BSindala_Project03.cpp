// Boniface Sindala
// CIS 251 (Spring 2013)
// Project 3
// Wednesday, April 24, 2013
// This program manages information about a 
// commercial property management company.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;

class RetailProp
{
public:
	RetailProp();
	//Initializes the idNumber to ??????, 
	//the tName to vacant, area to 0 and rent to 0.
	string get_id();
	//Returns idNumber.
	string get_tenant();
	//Returns tName.
	int get_area();
	//Returns area.
	double get_rent();
	//Returns rent.
	bool get_id_flag();
	//Returns flag for idNumber.
	bool get_area_flag();
	//Returns flag for tName.
	bool get_rent_flag();
	//Returns flag for rent.
	void set_id(string new_id);
	//Validates idNumber from input file.
	void set_tenant(string new_tenant);
	//Validates tName from input file.
	void set_area(int new_area);
	//Validates area from input file.
	void set_rent(double new_rent);
	//Validates rent from input file.
	void set_id_flag(bool new_flag);
	//Sets flag for idNumber.
	void set_area_flag(bool new_flag);
	//Sets flag for area.
	void set_rent_flag(bool new_flag);
	//Sets flag for rent.
	double getRentPerSqFoot(double prop_rent, int unit_price);
	//Returns the rent per sq. ft.
	void input(istream& ins);
	//Reads input from input file.
	void output(ostream& out);
	//Outputs to the screen.
private:
	string idNumber;
	string tName;
	int area;
	double rent;
	bool id_flag;
	bool area_flag;
	bool rent_flag;
};

int main()
{
	RetailProp property1, property2, property3, property4, property5;
	ifstream prop;
	prop.open("properties.txt");
	if (prop.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	property1.input(prop);
	property2.input(prop);
	property3.input(prop);
	property4.input(prop);
	property5.input(prop);
	property1.output(cout);
	property2.output(cout);
	property3.output(cout);
	property4.output(cout);
	property5.output(cout);

	prop.close();

	return 0;
}

RetailProp::RetailProp()
{
	idNumber = "??????";
	tName = "vacant";
	area = 0;
	rent = 0;
	id_flag = false;
	area_flag = false;
	rent_flag = false;
}

string RetailProp::get_id()
{
	return idNumber;
}

string RetailProp::get_tenant()
{
	return tName;
}

int RetailProp::get_area()
{
	return area;
}

double RetailProp::get_rent()
{
	return rent;
}

bool RetailProp::get_id_flag()
{
	return id_flag;
}

bool RetailProp::get_area_flag()
{
	return area_flag;
}

bool RetailProp::get_rent_flag()
{
	return rent_flag;
}

void RetailProp::set_id(string new_id)
{
	
	if (idNumber <= " ")
		idNumber = "??????";
	else
		idNumber = new_id;
}

void RetailProp::set_tenant(string new_tenant)
{
	if (tName <= " ")
		tName = "vacant";
	else
		tName = new_tenant;
}

void RetailProp::set_area(int new_area)
{
	if (area < 0)
		area = 0;
	else 
		area = new_area;
}

void RetailProp::set_rent(double new_rent)
{
	if (rent < 0)
		rent = 0;
	else
		rent = new_rent;
}

void RetailProp::set_id_flag(bool new_flag)
{
	id_flag = new_flag;
}

void RetailProp::set_area_flag(bool new_flag)
{
	area_flag = new_flag;
}

void RetailProp::set_rent_flag(bool new_flag)
{
	rent_flag = new_flag;
}
double RetailProp::getRentPerSqFoot(double prop_rent, int rented_area)
{
	return (rent/area); //Calculating the rent per sq. ft.
}

void RetailProp::input(istream& ins)
{
	ins >> idNumber >> tName >> area >> rent;
	if (idNumber.size() > 6) //Sets the number of characters for idNumber to 6.
	{
		set_id_flag(true);
	}
	if(area < 50) //Validates the area to be no less than 50 sq. ft.
	{
		set_area_flag(true);
	}
	set_area(area);
	if(rent < 500) //Validates the rent to be no less than $500.
	{
		set_rent_flag(true);
	}
	set_rent(rent);
}

void RetailProp::output(ostream& out)
{
	//Output formatting
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	if (idNumber == "??????")
	{
		out << "Error! Property information not entered.\n";
		cout << endl;
	}
	else
	{ //Outputs the validated input from the input file.
		if(id_flag == true)
		{
			cout << "Error: Identification Number should not be longer than six characters.\n";
			set_id_flag(false);
		}
		cout << "Property #" << idNumber << endl;
		replace(tName.begin(), tName.end(), '_', ' '); //Replaces all the '_' from tName with ' '.
		cout << "Occupied by " << tName << endl;
		if(area_flag == true)
		{
			cout << "Error: Area should not be less than 50 sq. ft.\n";
			set_area_flag(false);
		}
		cout << "Area: " << area << " sq. ft." << endl;
		if(rent_flag == true)
		{
			cout << "Error: Rent should not be less than $500.\n";
			set_rent_flag(false);
		}
		cout << "Rent: $" << rent << " ($" << getRentPerSqFoot(rent, area) << " per sq. ft.)" << endl << endl;
	}
}