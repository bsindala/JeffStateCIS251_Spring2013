//Boniface Sindala
//CIS 251 
//Lab Assignment 9
//March 25, 2013
//In this laboratory assignment, I will use C++ syntax
//to process several lines of text in an input file,
//displaying those lines of text that meet a certain criterion.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //For calling the exit function
using namespace std;

int main()
{
	ifstream info;
	string major;
	string student_data;
	int student_count = 0;
	
	info.open("studentInfo.csv"); //Opening the file
	if (info.is_open())
		{
			cout << "Please enter the major for the students to be dislayed.";
			getline (info, major, ',');
			cout << major << endl;
	}
	else if (info.fail()) //Fail function
	{
		cout << "Input file opening unsuccessful!" << endl;
		cout << "The program will now exit." << endl;
		exit(1);
	}
	/*cout << "Please enter the major for the students to be dislayed.";
	getline (info, major, ',');
	cout << major << endl;*/
	//Loop for major
	while (getline (info, major, ','))
	{
		if ((major == "Computer Science") || (major == "computer science"))
		{
			cout << "The students for " << major << endl;
			break;
		}
		else if ((major == "Biology") || (major == "biology"))
		{
			cout << "The students for " << major << endl;
			break;
		}
		else if ((major == "Chemistry") || (major == "chemistry"))
		{
			cout << "The students for " << major << endl;
			break;
		}
		else if ((major == "Mathematics") || (major == "mathematics"))
		{
			cout << "The students for " << major << endl;
			break;
		}
		else if ((major == "History") || (major == "history"))
		{
			cout << "The students for " << major << endl;
			break;
		}
		else if ((major == "English") || (major == "english"))
		{
			cout << "The students for " << major << endl;
			break;
		}
		else if ((major == "Political Science") || (major == "political science"))
		{
			cout << "The students for " << major << endl;
			break;
		}
		else
		{
			cout << "That major does not exist!" << endl;
			break;
		}
		getline(info, major, ',');
	}
	info.close();
	return 0;
}