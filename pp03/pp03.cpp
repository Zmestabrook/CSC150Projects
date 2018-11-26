/*
PP03 - Zackary Estabrook & Brennan Lamoreaux
Computer Science 150 10am
09/17/2018
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    double sum = 0;
    double average = 0;
    double max = 0;
    double stdDev = 0;
    double curve = 0;
    int numGrades = 0;
    int grade;
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int F = 0;
    double sumSquares = 0;
    int curveFinal = 0;

    cout << endl << "SDSMT Test Curve Calculator" << endl;
    cout << endl << "Enter the number of students: ";
    cin >> numGrades;

    for (int i = 0; i < numGrades; i++)
    {

        cout << "Enter the grade for student " << i + 1 << ": ";
        cin >> grade;

        if (grade <= 100 && grade >= 90)
        {
            A++;
        }
        else if (grade < 90 && grade >= 80)
        {
            B++;
        }
        else if (grade < 80 && grade >= 70)
        {
            C++;
        }
        else if (grade < 70 && grade >= 60)
        {
            D++;
        }
        else if (grade < 60)
        {
            F++;
        }

        if (i == 0) {
            max = grade;
        }
        else if (max < grade) {
            max = grade;
        }

        sumSquares = sumSquares + pow(grade, 2);
        sum = sum + grade;
        if (i == (numGrades - 1)) {
            // standard deviation 
            stdDev = sqrt(((numGrades * sumSquares) - pow(sum, 2)) / pow(numGrades, 2));
            //average
            average = sum / numGrades;
            //curve
            if (average < 70 && max != 100)
            {
                curve = ((75 - average) * 0.9) + 0.5;
                curveFinal = (int)curve;
            }
        }
    }

    cout << endl << "Number of A's : " << A;
    cout << endl << "Number of B's : " << B;
    cout << endl << "Number of C's : " << C;
    cout << endl << "Number of D's : " << D;
    cout << endl << "Number of F's : " << F;
    cout << endl;
    cout << endl << "Max           : " << max;
    cout << fixed << setprecision(3);
    cout << endl << "Average       : " << average;
    cout << endl << "Std Dev       : " << stdDev;
    cout << endl << "Curve         : " << curveFinal;
    cout << endl;

    return 0;
}