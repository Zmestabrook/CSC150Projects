#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// do not modify
const string MONTHNAMES[13] = { "UNUSED", "January", "February", "March", 
        "April", "May", "June", "July", "August", "September", "October",
        "November", "December" };
const int DAYS[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


// write prototypes here
int howManyDays(int month);
void readTemperature(int temperatures[], int monthsize);
int minTemp(int temperature[], int i);
int maxTemp(int temperature[], int i);
double averageTemp(int temperature[], int monthsize);




int main()
{
    int month = 0;
    int monthSize;
    cout << endl << "SDSMT Weather Center" << endl;
    cout << endl << "Enter the month (1-12): ";
    cin >> month;
    monthSize = DAYS[month];
    int i = monthSize;
    int hightemps[31];
    int lowtemps[31];
    double avgHigh = 0;
    double avgLow = 0;
    int high = 0;
    int low = 0;

    cout << endl << "Enter the highs: ";
    // enter your function call here to read the highs
    readTemperature( hightemps, monthSize);

    cout << endl << "Enter the lows: ";
    // enter your function call here to read the lows
    readTemperature(lowtemps, monthSize);

    // enter your function calls find lowest and average temperature
    avgLow = averageTemp(lowtemps, monthSize);
    avgHigh = averageTemp(hightemps, monthSize);




    // enter your function calls find highest and average temperature
    high = maxTemp(hightemps, monthSize);
    low = minTemp(lowtemps, monthSize);



    cout << fixed << showpoint << setprecision(1);
    cout << endl << "Monthly Report for " << MONTHNAMES[month];
    cout << endl << "Lowest Temperature: " << low;
    cout << endl << "Highest Temperature: " << high;
    cout << endl << "Average Low Temperature: " << avgLow;
    cout << endl << "Average High Temperature: " << avgHigh;
    cout << endl;

    return 0;
} 

// write your functions here
void readTemperature(int temperatures[], int monthsize)
{
    for (int i = 0; i < monthsize; i++)
    {
        cin >> temperatures[i];
    }
}

int minTemp(int temperature[], int monthsize)
{
    int i = 0;
    int low = temperature[0];
    for (i = 0; i < monthsize; i++)
    {
        if (temperature[i] < low)
        {
            low = temperature[i];
        }
    }
    return low;
}

int maxTemp(int temperature[], int monthsize)
{
    int i = 0;
    int max = i;
    for (i = 0; i < monthsize; i++)
    {
        if (temperature[i] > max)
        {
            max = temperature[i];
        }
    }
    return max;
}

double averageTemp(int temperature[], int monthsize)
{
    double total = 0;
    double average;
    for (int i = 0; i < monthsize; i++)
    {
        total += temperature[i];
    }
    average = total / monthsize;
    return average;
}