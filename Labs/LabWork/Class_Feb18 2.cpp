#include <iostream>
using namespace std;

void changeThem(int p1, int& p2); 

int main()
{
    int a1 = 9, a2 = 4;

    cout << "Before the Call:" << endl;
    cout << "Argument 1: " << a1 << endl;
    cout << "Argument 2: " << a2 << endl;

    changeThem(a1, a2);

    cout << "After the Call:" << endl;
    cout << "Argument 1: " << a1 << endl;
    cout << "Argument 2: " << a2 << endl;

    return 0;
}

void changeThem(int p1, int& p2)
{
    p1 = 5;
    cout << "Parameter 1: " << p1 << endl;
    p2 = 7;
    cout << "Parameter 2: " << p2 << endl;
}
