#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	ifstream originalFile;
	ofstream newFile;
	char fileName[31];
	int val1, val2, val3;

	cout << "What file would you like to open? ";
	cin >> fileName;
	originalFile.open(fileName);
	while (originalFile.fail())
	{
		cout << "Error! " << fileName << " file does not exist." << endl;
		cout << "Enter a different file name: ";
		cin >> fileName;
		originalFile.open(fileName);
	}
	newFile.open("New.txt");

	originalFile >> val1 >> val2 >> val3;
	newFile << val1 << setw(8) << val2 << setw (8) << val3 << endl;

	originalFile.close();
	newFile.close();

	return 0;
}
	