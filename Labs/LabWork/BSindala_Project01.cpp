// Boniface Sindala
// CIS 251 (Spring 2013)
// Project 1
// Wednesday, March 13, 2013
// In this project, the user enters the distance in kilometers,
// the speed in miles per hour.
// The program displays the number of hours, minutes and seconds 
// the journey will take.
#include <iostream>
#include <iomanip>
using namespace std;
double kilometer = 0;
const double milesPerKilometer = 0.6213712;

double converts_km_to_miles(double kilometer, double miles_equivalent);
//Precondition: Function converts kilometers to miles.
//Enter kilometers in the function.

int calculate_time(double miles, double speed);
//Precondition: Function calculates the time and displays 
//the time in hours, minutes and seconds.

int main()
{
	double kilom = 0, in_miles = 0, pace = 0;
	int time;
	char ans;
	cout << "Program to calculate the time taken to travel." << endl
		 << "When the distance and speed is given." << endl << endl;

	//Display formatting for the kilometers to miles display
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	//Calling of function to calculate the time
	time = calculate_time(in_miles, pace);

	cout << endl << "Do you wish to calculate the time for another object (Y/N)? ";
	cin >> ans;
	
	while ((ans == 'y') || (ans == 'Y'))
	{
		cout << endl;
		time = calculate_time(in_miles, pace);
		cout << "Do you wish to calculate the time for another object (Y/N)? ";
		cin >> ans;
	}
	if ((ans == 'n') || (ans == 'N'))
		cout << "The program will now exit." << endl;
	else
		cout << "Choice not recognized, the program will now exit." << endl;
	return 0;
}

//Function definition for converting kilometers to miles
double converts_km_to_miles(double kilometer, double miles_equivalent)
{
	double miles = 0;
	cout << "Please enter the distance in kilometers: ";
	cin >> kilometer;
	miles = kilometer / milesPerKilometer; //Conversion of kilometers to miles
	cout << kilometer << " kilometers = " << miles << " miles." << endl << endl;
	return miles;
}

//Function definition for calculating the time
int calculate_time(double miles, double speed)
{
	int hours = 0, minutes = 0, time = 0, seconds = 0, remainder1, remainder2;
	double mile = 0, inmiles = 0, _speed, speed_in_seconds = 0;
	const int secondsPerHour = 3600, secondsPerMinute = 60;

	mile = converts_km_to_miles(kilometer, inmiles); //Function calling for the kilometers converted into miles
	cout << "To calculate the time taken to travel: " << endl;
	cout << "Please enter the speed in miles per hour (mph): ";
	cin >> _speed;
	
	//Calculation of hours, minutes and seconds
	speed_in_seconds = _speed / 3600;
	time = mile / speed_in_seconds;
	hours = time / secondsPerHour;
	remainder1 = time % secondsPerHour;
	minutes = remainder1 / secondsPerMinute;
	remainder2 = remainder1 % secondsPerMinute;
	seconds = remainder2;
	cout << "The journey took (h:mm:ss): ";
	cout << hours << ":" << setfill('0') << setw(2) << minutes << ":" 
		 << setfill('0') << setw(2) << seconds << endl; //Display of hours, minutes and seconds the object took to travel
	
	return (time);

}