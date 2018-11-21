#include <iostream>
#include <iomanip>
using namespace std;
const int NUM_STUDENTS = 4, NUM_QUIZZES = 3;

void computeStudentAvg(const int grade[][NUM_QUIZZES], double stuAvg[]);
void computeQuizAvg(const int grade[][NUM_QUIZZES], double quizAvg[]);
void display(const int grade[][NUM_QUIZZES], const double stuAvg[], 
             const double quizAvg[]);

int main()
{
    int grade[NUM_STUDENTS][NUM_QUIZZES];
    double stuAvg[NUM_STUDENTS];
    double quizAvg[NUM_QUIZZES];

    for (int stuNum = 1; stuNum <= NUM_STUDENTS; stuNum++)
    {
        cout << "Student #" << stuNum << endl;
        for (int qNum = 1; qNum <= NUM_QUIZZES; qNum++)
        {
            cout << "Enter grade for quiz " << qNum << ": ";
            cin >> grade[stuNum - 1][qNum - 1];
        }
        cout << endl;
    }

    computeStudentAvg(grade, stuAvg);
    computeQuizAvg(grade, quizAvg);
    display(grade, stuAvg, quizAvg);
    return 0;
}
void computeStudentAvg(const int grade[][NUM_QUIZZES], double stuAvg[])
{
    // Outer loop:  students
    for (int stuNum = 1; stuNum <= NUM_STUDENTS; stuNum++)
    {
        double sum = 0;

        // Inner loop:  quizzes
        for (int quizNum = 1; quizNum <= NUM_QUIZZES; quizNum++)
            sum = sum + grade[stuNum - 1][quizNum - 1];

        stuAvg[stuNum - 1] = sum / NUM_QUIZZES;
    }
}
void computeQuizAvg(const int grade[][NUM_QUIZZES], double quizAvg[])
{
    // Outer loop:  quizzes
    for (int quizNum = 1; quizNum <= NUM_QUIZZES; quizNum++)
    {
        double sum = 0;

        // Inner loop:  students
        for (int stuNum = 1; stuNum <= NUM_STUDENTS; stuNum++)
            sum = sum + grade[stuNum - 1][quizNum - 1];

        quizAvg[quizNum - 1] = sum / NUM_STUDENTS;
    }
}
void display(const int grade[][NUM_QUIZZES], const double stuAvg[], 
    const double quizAvg[])
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << setw(10) << "Student" << setw(5) << "Avg" 
         << setw(15) << "Quizzes\n";

    for (int stuNum = 1; stuNum <= NUM_STUDENTS; stuNum++)
    {
        cout << setw(10) << stuNum << setw(5) << stuAvg[stuNum - 1] 
             << " ";
        for (int quizNum = 1; quizNum <= NUM_QUIZZES; quizNum++)
            cout << setw(5) << grade[stuNum - 1][quizNum - 1];
        cout << endl;
    }

    cout << "Quiz averages = ";
    for (int quizNum = 1; quizNum <= NUM_QUIZZES; quizNum++)
        cout << setw(5) << quizAvg[quizNum - 1];
    cout << endl;
}
