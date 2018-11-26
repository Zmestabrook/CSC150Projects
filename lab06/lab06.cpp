#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    const double tax = 1.06;
    bool member = false;
    bool taxable = true;
    char ch;
    int items = 0;
    double item = 0;
    int num = 0;
    double discount = 0.00;
    double discountneg = 0.00;
    double amountTax = 0.00;
    double subtotal = 0;
    double price = 0;
    double priceTotal = 0;
    double priceTotaltax = 0;

    cout << endl << "SDSM&T TechMart" << endl;

    cout << endl << "Are you a club member (y/n): ";
    //cin.get(ch);
    cin >> ch;
    if (ch == 'y')
    {
        member = true;
    }
    
    //cin.ignore();
    cout << endl << "Are you taxed exempt (y/n): ";
    //std::cin.get(ch);
    cin >> ch;
    if (ch == 'y')
    {
        taxable = false;
    }
    
    
    cout << endl << "Enter price: ";

    while ( cin >> price )
    {
        
        subtotal += price;
        cout << endl << "Enter price: ";
        items++;
    }
    //let me commit
    if (!member)
    {
        priceTotal = subtotal;
    }
    if (member)
    {
        priceTotal = subtotal * .90;
        discount = subtotal - priceTotal;
        discountneg = discount * -1;
    }
    if (taxable)
    {
        priceTotaltax = subtotal * tax;
        amountTax = priceTotaltax - subtotal;
        priceTotal = priceTotaltax - discount;
    }

    //final outputs
    cout << fixed << showpoint << setprecision(2);
    cout << endl << "Items Purchased : " << setw(5) << items;
    cout << endl << "Sub Total       $ " << setw(8) << subtotal;
    cout << endl << "Member Discount $ " << setw(8) << discountneg;
    cout << endl << "Tax             $ " << setw(8) << amountTax;
    cout << endl << "Total Bill      $ " << setw(8) << priceTotal;
    cout << endl;
    return 0;
}