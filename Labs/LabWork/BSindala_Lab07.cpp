// Boniface Sindala
// CIS 251 (Spring 2013)
// Laboratory Assignment 7
// Friday, March 1, 2013
// In this assignment, I will learn how to use C++ syntax
// to read data from a file and write it to four seperate files
// based on certain criteria.
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void majorClasses(ifstream& cis, ofstream& app, ofstream& net, ofstream& prog, ofstream& web);
//Calls the function to place the student in respective majors

int main()
{
	ifstream cis;
	ofstream app, net, prog, web;

	cout << "The class seperation according to majors has started!" << endl << endl;
	cis.open("cisdegree.txt"); //Open the original file
	if (cis.fail())
	{
		cout << "Input file opening failed!" << endl;
		cout << "The program will exit now" << endl;
		exit(1);
	}
	app.open("appmajors.txt"); //Opening the new files
	net.open("netmajors.txt");
	prog.open("progmajors.txt");
	web.open("webmajors.txt");

	app.setf(ios::fixed); //Number formatting
	app.setf(ios::showpoint);
	app.precision(2);
	net.setf(ios::fixed);
	net.setf(ios::showpoint);
	net.precision(2);
	prog.setf(ios::fixed);
	prog.setf(ios::showpoint);
	prog.precision(2);
	web.setf(ios::fixed);
	web.setf(ios::showpoint);
	web.precision(2);
	
	majorClasses(cis, app, net, prog, web); //Function calling

	cis.close(); //Closing the new files
	app.close();
	net.close();
	prog.close();
	web.close();
	
	return 0;
}

void majorClasses(ifstream& cis, ofstream& app, ofstream& net, ofstream& prog, ofstream& web) //Defining the function
{
	int studentNumber = 0;
	string lastName, firstName;
	char middle_initial[2], major;
	double gpa = 0;
	cis >> studentNumber >> lastName >> firstName >> middle_initial >> gpa >> major;
		while (! cis.eof())
		{
			switch (major)
			{
			case 'A':
				
				app << studentNumber << " "<< lastName << " " << firstName
				<< " " << middle_initial << endl;
				break;
			case 'N':
				
				net << studentNumber << " "<< lastName << " " << firstName
				<< " " << middle_initial << endl;
				break;
			case 'P':
				
				prog << studentNumber << " "<< lastName << " " << firstName
				<< " " << middle_initial << endl;
				break;
			case 'W':
				
				web << studentNumber << " "<< lastName << " " << firstName
				<< " " << middle_initial << endl;
				break;
			default:
				break;
			}
			cis >> studentNumber >> lastName >> firstName >> middle_initial >> gpa >> major;
		}
	cout << "Process finished!" << endl;
}