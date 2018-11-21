//Boniface Sindala
//CIS251
//Laboratory Assignment 12
//April 22, 2013
//Laboratory assignment on the use of C++ syntax
//to add operators to a class definition.
#include <iostream>
using namespace std;

class DayOfYear
{
public:
	DayOfYear(int theMonth, int theDay);
	DayOfYear(); //Initializes day and month to both 1s
    void setMonth(int newMonth);
    void setDay(int newDay);
    int getMonth();
    int getDay();
    friend istream& operator >> (istream& input, DayOfYear object);
    friend ostream& operator << (ostream& output, const DayOfYear object);
	friend bool operator ==(const DayOfYear& date1, const DayOfYear& date2);
private:
    int month;
    int day;
};


int main()
{
	DayOfYear today, next_today;
	cout << "Please enter today's date\n"
		 << "(Enter in number form (mm dd) seperated by a space): ";
	cin >> today;
	cout << "Please enter another date\n"
		 << "(Enter in number form (mm dd) seperated by a space): ";
	cin >> next_today;
	cout << "Day #1: " << today << endl;
	cout << "Day #2: " << next_today << endl;
	if (today == next_today)
		cout << "The dates are the same." << endl;
	else
		cout << "The dates are different." << endl;
	return 0;
}

bool operator ==(const DayOfYear& date1, const DayOfYear& date2) //Compares the 2 dates
{
	return ((date1.month == date2.month) &&
		(date1.day == date2.day));
}

DayOfYear::DayOfYear(int theMonth, int theDay)
{
	if ((theMonth >= 1) && (theMonth <= 12) && (theDay >= 1) && (theDay <= 31))
	{
		month = theMonth;
		day = theDay;
	}
	else
	{
		cout << "Error!  Invalid initial value for month and / or day." << endl;
		cout << "Setting both values to 1." << endl;
		month = 1;
		day = 1;
	}
}

DayOfYear::DayOfYear()
{
	month = 1;
	day = 1;
}

void DayOfYear::setMonth(int newMonth)
{
    if ((newMonth >= 1) && (newMonth <= 12))
    	month = newMonth;
    else
    	cout << "Error!  The month must be between 1 and 12." << endl;
}

void DayOfYear::setDay(int newDay)
{
    if ((newDay >= 1) && (newDay <= 31))
    	day = newDay;
    else
    	cout << "Error!  The month must be between 1 and 31." << endl;
}

int DayOfYear::getMonth()
{
    return month;
}

int DayOfYear::getDay()
{
    return day;
}

istream& operator >> (istream& input, DayOfYear object) //Input function
{
	int tempMonth, tempDay;
	
    input >> tempMonth;
	object.month = tempMonth;

    input >> tempDay;
    object.day = tempDay;
	return input;
}

ostream& operator << (ostream& out, const DayOfYear object) //Output function
{
    out << "month = " << object.month << ", day = " << object.day << endl;
	return out;
}