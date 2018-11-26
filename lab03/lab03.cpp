// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//global constants
const double PI = atan(1.0) * 4;    //PI out to 15 digits
const double MOWINGCOST = .00275;   //cost to mow per sqr ft
const double TRIMMINGCOST = .08;    //cost to trim per linear ft

int main()
{
    //vars
    double lotWidth = 0;;
    double lotLength = 0;;
    double houseWidth = 0;
    double houseLength = 0;
    double siloRadius = 0;    
    double shedSide = 0;
    double gazeboSide = 0;
    double lotArea;

    //display prompts
    cout << "Mowing Calculator" << endl;
    cout << "All dimensions are given in feet." << endl;
    cout << endl;

    cout << "Enter the dimensions of the lot, width and length: ";
    cin >> lotWidth >> lotLength;
    lotArea = lotWidth * lotLength;
    cout << "Enter the dimensions of the house, width and length: ";
    cin >> houseWidth >> houseLength;
    double houseArea = houseWidth * houseLength;
    double housePerimeter = (houseLength * 2) + (houseWidth * 2);

    cout << "Enter the dimension of the shed, length: ";
    cin >> shedSide;
    double shedPerimeter = shedSide + shedSide + shedSide + shedSide;
    double shedArea = pow(shedSide, 2);

    cout << "Enter the radius of the silo: ";
    cin >> siloRadius;
    double siloArea = PI * pow(siloRadius, 2);
    double siloPerimeter = 2 * PI * siloRadius;

    cout << "Enter the dimension of the gazebo, length: ";
    cin >> gazeboSide;
    double gazeboArea = 2 * ((1 + sqrt(2))* pow(gazeboSide, 2));
    double gazeboPerimeter = 8 * gazeboSide;

    double unmowableArea = houseArea + siloArea + gazeboArea + shedArea;
    double mowableArea = lotArea - unmowableArea;
    double trimmableLength = housePerimeter + siloPerimeter + gazeboPerimeter + shedPerimeter;
    double moneyForMowing = mowableArea * MOWINGCOST;
    double moneyForTrimming = trimmableLength * TRIMMINGCOST;
    double moneyforJob = moneyForMowing + moneyForTrimming;
    cout << endl << endl;
    //display output

    cout << fixed << setprecision(1);
    cout << "Areas given in square feet" << endl;
    cout << "Base Lot Area :" << setw(10) << lotArea << endl;
    cout << "House Area    :" << setw(10) << houseArea << endl;
    cout << "Shed Area     :" << setw(10) << shedArea << endl;
    cout << "Silo Area     :" << setw(10) << siloArea << endl;
    cout << "Gazebo Area   :" << setw(10) << gazeboArea << endl;
    cout << "Mowing Area   :" << setw(10) << mowableArea << endl;
    cout << "Trimming Feet :" << setw(10) << trimmableLength << endl;
    cout << endl;

    cout << fixed << setprecision(2);
    cout << "Billing" << endl;
    cout << "Mowing Cost   $" << setw(10) << moneyForMowing << endl;
    cout << "Trimming Cost $" << setw(10) << moneyForTrimming << endl;
    cout << "Total Bill    $" << setw(10) << moneyforJob << endl;

    return 0;

}
