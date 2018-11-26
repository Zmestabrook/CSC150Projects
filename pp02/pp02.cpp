/*
PP02 In class project
Zackary Estabrook & Dreu Adams
09/07/2018
*/

#include <iostream>
#include <iomanip>

using namespace std;
//vars 



int main()
{

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    cout << "Enter a, b, c: ";
    cin >> num1 >> num2 >> num3;

    if ( num1 + num2 == num3) {
        cout << "Addition" << endl;
    }

    if ( num1 - num2 == num3 || num2 - num1 == num3) {
        cout << "Subtraction" << endl;
    }

    if ( num1 * num2 == num3) {
        cout << "Multiplication" << endl;
    }
    if (num1 / num2 == num3 || num2 / num1 == num3) {
        cout << "Division" << endl;

    }
    if (num1 % num2 == num3 || num2 % num1 == num3) {
        cout << "Modulus" << endl;
    }
    return 0;
}