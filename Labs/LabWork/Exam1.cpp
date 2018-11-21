#include <iostream>
using namespace std;

int main()
{
	int chicken = 3, turkey = 60, ham = 8;

	while (chicken < turkey)
	{
		cout << "Nugget: " << chicken << endl;
		cout << "Slice: " << turkey << endl;
		chicken = chicken +2;
		turkey = turkey / 2;
	}

	if (turkey < ham)
	{
		cout << "Gobble gobble! " << turkey << endl;
		turkey += chicken;
	}
	else
	{
		cout << "Oink oink! " << ham << endl;
		ham += chicken;
	}

	cout << "Scared: " << chicken << endl;
	cout << "Country: " << turkey << endl;
	cout << "Showy: " << ham << endl;

	return 0;
}