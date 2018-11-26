//NAME: 
//CSC 150 Lab 04 Fall 2018
//Pet Food Discount Calculation
//If, nested if, else if

//PROMPTS
//Move these lines to the appropriate places in your program.
//Change VARIABLE to appropriate variable or expression.
//fix so you dont need to return 0 after every if/elseif



#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

    char confirm;
    string petType = "Other"; 
    int petNumber = 0;
    double pricePreDiscountAndTax =0;
    double priceAfterTax = 0;
    double discount = 0;
    double discountTotal = 0;
    double priceAfterDiscount = 0;
    const double SALES_TAX_RATE = 0.07;


    

    cout << "Do you have a pet (Y/N)? ";
    cin >> confirm;
    if (confirm == 'N' || confirm == 'n') {
        cout << fixed << showpoint << setprecision(2);
        discount = 0;

        cout << endl << "Enter purchase subtotal: ";
        cin >> pricePreDiscountAndTax;

        priceAfterDiscount = (pricePreDiscountAndTax  * (1 - discount));
        cout << endl << "Subtotal after discount: $" << priceAfterDiscount;

        priceAfterTax = priceAfterDiscount * (1 + SALES_TAX_RATE);
        cout << endl << "Final total: $" << priceAfterTax << endl;
        
       
    }
    else if (confirm == 'Y' || confirm == 'y') {

    }

    cout << endl << "What kind of pet? ";
    cin >> petType;
    cout << endl << "How many? ";
    cin >> petNumber;
    
    cout << fixed << showpoint << setprecision(2);

    if (petType == "Dog" || petType == "dog") {
        if (petNumber > 4) {
            discount = .2;
            cout << endl << "Enter purchase subtotal: ";
            cin >> pricePreDiscountAndTax;

            priceAfterDiscount = ((1 - discount) * pricePreDiscountAndTax  );
            cout << endl << "Subtotal after discount: $" << priceAfterDiscount;

            priceAfterTax = priceAfterDiscount * (1 + SALES_TAX_RATE);
            cout << endl << "Final total: $" << priceAfterTax << endl;

            
        }
        else if (petNumber <= 4 && petNumber > 0) {
            discount = .15;
            cout << endl << "Enter purchase subtotal: ";
            cin >> pricePreDiscountAndTax;

            priceAfterDiscount = ((1 - discount) * pricePreDiscountAndTax);
            cout << endl << "Subtotal after discount: $" << priceAfterDiscount;

            priceAfterTax = priceAfterDiscount * (1 + SALES_TAX_RATE);
            cout << endl << "Final total: $" << priceAfterTax << endl;

           
        }
    }

    if (petType == "Cat" || petType == "cat") {
        if (petNumber >= 5) {
            discount = .3;
            cout << endl << "Enter purchase subtotal: ";
            cin >> pricePreDiscountAndTax;

            priceAfterDiscount = ((1 - discount) * pricePreDiscountAndTax);
            cout << endl << "Subtotal after discount: $" << priceAfterDiscount;

            priceAfterTax = priceAfterDiscount * (1 + SALES_TAX_RATE);
            cout << endl << "Final total: $" << priceAfterTax << endl;

        }
        else if (petNumber < 5 && petNumber > 0) {
            discount = .25;
            cout << endl << "Enter purchase subtotal: ";
            cin >> pricePreDiscountAndTax;

            priceAfterDiscount = ((1 - discount) * pricePreDiscountAndTax);
            cout << endl << "Subtotal after discount: $" << priceAfterDiscount;

            priceAfterTax = priceAfterDiscount * (1 + SALES_TAX_RATE);
            cout << endl << "Final total: $" << priceAfterTax << endl;
            
        }
    } else if (petType != "Dog" && petType != "dog" && petType != "Cat" && petType != "cat" ) {
        if (petNumber > 2) {
            discount = .1;
            cout << endl << "Enter purchase subtotal: ";
            cin >> pricePreDiscountAndTax;

            priceAfterDiscount = ((1 - discount) * pricePreDiscountAndTax);
            cout << endl << "Subtotal after discount: $" << priceAfterDiscount;

            priceAfterTax = priceAfterDiscount * (1 + SALES_TAX_RATE);
            cout << endl << "Final total: $" << priceAfterTax << endl;

           
        }
        else if (petNumber <= 2 && petNumber > 0) {
            discount = .05;
            cout << endl << "Enter purchase subtotal: ";
            cin >> pricePreDiscountAndTax;

            priceAfterDiscount = ((1 - discount) * pricePreDiscountAndTax);
            cout << endl << "Subtotal after discount: $" << priceAfterDiscount;

            priceAfterTax = priceAfterDiscount * (1 + SALES_TAX_RATE);
            cout << endl << "Final total: $" << priceAfterTax << endl;

           
        }
    }
   
    
    
    




    




    return 0;
}