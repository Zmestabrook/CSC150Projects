// Names: Zackary Estabrook & Dominick Jackson
// Date: 08/31/2018
//PP01: Pizza Calculator

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //vars
    int totalPizzas;
    int slices;
    int peopleFed;
    int totalSlices;
    int slicesPerPerson;
    int leftoverSlices;
    int slicesEaten;
    double pizzaCost;
    double pricePerPerson;
    double pricePerSlice;
    double amountSpent;

    //part1
    cout << "Pizza Calculator" << endl << endl;

    cout << "Please enter the number of pizzas: ";
    cin >> totalPizzas;

    cout << "Please enter the number of slices per pizza: ";
    cin >> slices;

    cout << "Please enter the number of people: ";
    cin >> peopleFed;

    cout << endl;

    totalSlices = totalPizzas * slices;
    cout << "There are " << totalSlices << " total slices." << endl;
    
    slicesPerPerson = totalSlices / peopleFed;
    cout << "Each person gets " << slicesPerPerson << " slices." << endl;

    slicesEaten = slicesPerPerson * peopleFed;
    leftoverSlices = totalSlices % peopleFed;
    cout << "There are " << leftoverSlices << " slices left over." << endl << endl;
  

    //part2
    cout << "How much was the cost of each pizza: ";
    cin >> pizzaCost;
    cout << endl;
    cout << fixed << setprecision(2);

    amountSpent = pizzaCost * totalPizzas;
    pricePerSlice = amountSpent / totalSlices;
    cout << "Each slice cost $" << pricePerSlice << endl;

    pricePerPerson = pricePerSlice * slicesPerPerson;
    cout << "Each person's pizza cost was $" << pricePerPerson << endl;

    
    cout << "The entire meal cost $" << amountSpent << endl;


    return 0;
}