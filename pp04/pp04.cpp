/* 
    Zackary Estabrook & Dreu Adams
    PP04
    CSC150
    9/28/2018
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;
using namespace std;
using namespace std;

int main()
{
    double disposable = 0;
    double depSum = 0;
    double checkSum = 0;
    double expenseSum = 0;
    double startingBalance = 0;
    double deposit = 0;
    double check = 0;
    double expenses = 0;
    double available = 0;
    string prompt = "";
    double sentinelIteration( string );

    cout << "Financial Awareness";

    cout << endl << "Enter your starting balance $ ";
    cin >> startingBalance;

    cout << endl << "DEPOSITS";
    prompt = "DEPOSITS";
    depSum = sentinelIteration( "Enter deposit amount $ " );

    cout << endl << "CHECKS";
    prompt = "CHECKS";
    checkSum = sentinelIteration("Enter check amount $ " );

    cout << endl << "EXPENSES";
    prompt = "EXPENSES";
    expenseSum = sentinelIteration("Enter expense amount $ ");

    
    //output


    cout << fixed << showpoint << setprecision(2);
    cout << endl;
    cout << endl << "      Financial Summary";
    cout << endl << "==============================";
    cout << endl << "Starting Balance  $ " << setw(10) << startingBalance;
    cout << endl << "Deposits          $ " << setw(10) << depSum;
    cout << endl << "Checks            $ " << setw(10) << checkSum;
    cout << endl << "Expenses          $ " << setw(10) << expenseSum;
    disposable = startingBalance + depSum - checkSum - expenseSum;
    cout << endl << "Disposable Income $ " << setw(10) << disposable;
    cout << endl;

    return 0;
}

double sentinelIteration( string prompt )
{
    double sum = 0;
    double value;
    cout << endl << "-1 terminates input" << endl;
    cout << prompt;
    cin >> value;
    while (value != -1)
    {
        sum += value;
        cout << prompt;
        cin >> value;
    }
    return sum;

}