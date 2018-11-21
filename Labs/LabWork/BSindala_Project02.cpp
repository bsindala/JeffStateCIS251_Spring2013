// Boniface Sindala
// CIS 251 (Spring 2013)
// Project 2
// Tuesday, April 2, 2013
// This program locates agents for various
// types of insurance.
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream agents;
	ofstream local, bZip, bPhone;
	string lastName, firstName, insurance, insurance1;
	string company;
	long int zip, zip1;
	unsigned long int phone;

	cout << "Please enter the type of insurance coverage you want: "; //Use input
	cin >> insurance1;
	cout << "Please enter your new zip code: ";
	cin >> zip1;
	agents.open("agents.txt"); //File opening
	if (agents.fail()) //Calling the exit function if input file not opened successfully
	{
		cout << "Input file opening unsuccessful.\n"
			 << "Program will now exit!\n" << endl;
		exit(1);
	}
	local.open("localAgents.txt");
	bZip.open("badZip.txt");
	bPhone.open("badPhone.txt");
	agents >> lastName >> firstName >> company >> insurance >> zip >> phone;

	while (! agents.eof()) //Loop for searching through the input file to generate an output file.
	{
		if ((insurance1 == insurance) && (zip1 == zip))
		{
			local << insurance << " Agents in Zip Code " << zip << endl;
			local << left << setw(25) << string(lastName + ", " + firstName) //Formatted with left alignment and setwidth accordingly
				  << left << setw(15) << company
				  << left << setw(10) << phone;
			break;
		}
		else if ((insurance1 == insurance) && (zip1 == zip) && (zip1 <= 0) || (zip1 <= 52999)) //Bad zip code loop
		{
			bZip << insurance << " Agents in Zip Code " << zip << endl;
			bZip << lastName << " " << firstName << " " << company << " " << insurance << " " << zip << " " << phone;
			break;
		}
		else if ((insurance1 == insurance) && (zip1 == zip) && (phone <= 0) || (phone <= 4139999999)) //Bad phone number loop
		{
			bPhone << insurance << " Agents in Zip Code " << zip << endl;
			bPhone << lastName << " " << firstName << " " << company << " " << insurance << " " << zip << " " << phone;
			break;
		}
		agents >> lastName >> firstName >> company >> insurance >> zip >> phone;
	}
	agents.close();
	local.close();
	bZip.close();
	bPhone.close();
	return 0;
}