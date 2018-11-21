#include <iostream>
using namespace std;

int main()
{
    const int STUDENTS = 12;
    int stuCount, stuGrades[STUDENTS];

    for (stuCount = 0; stuCount < STUDENTS; stuCount++)
    {
        cout << "Enter score #" << stuCount + 1 << ": ";
        cin >> stuGrades[stuCount];
    }

    cout << "Here are the scores you entered: " << endl;

    for (stuCount = 0; stuCount < STUDENTS; stuCount++)
        cout << "Score #" << stuCount + 1 << ": "
             << stuGrades[stuCount] << endl;

    return 0;
}