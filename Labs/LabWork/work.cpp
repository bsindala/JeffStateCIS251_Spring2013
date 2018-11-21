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

int main()
{
	int student_number;
	string last_name, first_name;
	char middle_initial[2], major_code[2];
	double gpa;
	ifstream icisdegree;
	ofstream oappmajors, onetmajors, oprogmajors, owebmajors;

	cout << "The division of students according to seperate majors begins now!";
	icisdegree.open("cisdegree.txt");
	if (icisdegree.fail()) //Calling the fail function to exit
	{
		cout << "Input file opening failed!" << endl;
		cout << "The program will exit now" << endl;
		exit(1);
	}

	oappmajors.open("appmajors.txt", ios::app);
	onetmajors.open("netmajors.txt", ios::app);
	oprogmajors.open("progmajors.txt", ios::app);
	owebmajors.open("webmajors.txt", ios::app);

	oappmajors.setf(ios::fixed); //Set these for gpa
	oappmajors.setf(ios::showpoint);
	oappmajors.precision(2);
	onetmajors.setf(ios::fixed);
	onetmajors.setf(ios::showpoint);
	onetmajors.precision(2);oprogmajors.setf(ios::fixed);
	oprogmajors.setf(ios::showpoint);
	oprogmajors.precision(2);
	owebmajors.setf(ios::fixed);
	owebmajors.setf(ios::showpoint);
	owebmajors.precision(2);

	icisdegree.get(major_code);
	while (!icisdegree.eof()) //come back to this
	{
		if (major_code == 'A')
		{
			oappmajors << student_number << " "<< last_name << " " << first_name
				<< " " << middle_initial << " " << gpa << endl;
			break;
		}
		else if (major_code == 'N')
		{
			onetmajors << student_number << " "<< last_name << " " << first_name
				<< " " << middle_initial << " " << gpa << endl;
			break;
		}
		else if (major_code == 'P')
		{
			oprogmajors << student_number << " "<< last_name << " " << first_name
				<< " " << middle_initial << " " << gpa << endl;
			break;
		}
		else if (major_code == 'W')
		{
			owebmajors << student_number << " "<< last_name << " " << first_name
				<< " " << middle_initial << " " << gpa << endl;
			break;
		}
		icisdegree.get(major_code);
	}
	
	icisdegree.close();
	oappmajors.close();
	onetmajors.close();
	oprogmajors.close();
	owebmajors.close();

	return 0;
}