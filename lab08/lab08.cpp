#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <cmath>
#include <iomanip>
#include "..\catch.hpp"

using namespace std;

//write your function prototypes here
void convertToPolar(double x, double y, double &length, double &angle);
void convertToCart(double length, double angle, double &x, double &y);
void getInputs(double &input1, double &input2);
char getMenuChoice();


int main(int argc, char *argv[])
{
    // define your variables here

    char choiceUp;
    double input1, input2;
    double x, y;
    double length, angle;

    int result = Catch::Session().run(argc, argv);
    if (result != 0)
    {
        cout << "Some of your functions are not passing the requirements."
            << endl;
        return 1;
    }

    // write your main function code here
    choiceUp = getMenuChoice();
    getInputs(input1, input2);
    if( choiceUp == 'C')
    {
        x = input1;
        y = input2;
        cout << fixed << setprecision(4);
        convertToPolar(x, y, length, angle);
        cout << "length: " << length << " angle: " << angle;
    }
    else if (choiceUp == 'P')
    {
        length = input1;
        angle = input2;
        cout << fixed << setprecision(4);
        convertToCart(length, angle, x, y);
        cout << "x: " << x << " y: " << y;
    }





    return 0;
}


// write your functions here above the test cases.
//why should it be length then angle?
void convertToPolar(double x, double y, double &length, double &angle)
{
    length = sqrt(pow(x, 2) + pow(y, 2));
    angle = atan(y / x);
}



void convertToCart(double length, double angle, double &x, double &y)
{
    x = length * cos(angle);
    y = length * sin(angle);
}
void getInputs(double &input1, double &input2)
{
    cout << "Enter coordinates: ";
    cin >> input1 >> input2;
}







char getMenuChoice()
{
    char choice;
    cout << "Polar and Cartesian Coordinate Conversion" << endl;
    cout << "Convert (P)olar to Cartesian " << endl;
    cout << "Convert (C)artesian to Polar " << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return toupper(choice);
} 





















TEST_CASE("convertToPolar test cases")
{
    double x, y, length, angle, myLength, myAngle;
    double tolerance = 0.001;

    x = 100;
    y = 100;
    myLength = sqrt(20000);
    myAngle = 3.14159 / 4.0;
    convertToPolar(x, y, length, angle);
    REQUIRE(abs(length - myLength) < tolerance);
    REQUIRE(abs(angle - myAngle) < tolerance);

    x = 10.013;
    y = 100;
    myLength = 100.5;
    myAngle = 1.471;
    convertToPolar(x, y, length, angle);
    REQUIRE(abs(length - myLength) < tolerance);
    REQUIRE(abs(angle - myAngle) < tolerance);


    x = 2.7;
    y = 25;
    myLength = 25.145;
    myAngle = 1.4632;
    convertToPolar(x, y, length, angle);
    REQUIRE(abs(length - myLength) < tolerance);
    REQUIRE(abs(angle - myAngle) < tolerance);
}

TEST_CASE("convertToCart test cases")
{
    double length, angle, x, y, my_x, my_y;
    double tolerance = 0.001;

    length = 13.7481;
    angle = 1.1592;
    my_x = 5.5002;
    my_y = 12.599;
    convertToCart(length, angle, x, y);
    REQUIRE(abs(x - my_x) < tolerance);
    REQUIRE(abs(y - my_y) < tolerance);

    length = 26;
    angle = 0.79;
    my_x = 18.3;
    my_y = 18.47;
    convertToCart(length, angle, x, y);
    REQUIRE(abs(x - my_x) < tolerance);
    REQUIRE(abs(y - my_y) < tolerance);

    length = 2044;
    angle = 0.2;
    my_x = 2003.2561;
    my_y = 406.0801;
    convertToCart(length, angle, x, y);
    REQUIRE(abs(x - my_x) < tolerance);
    REQUIRE(abs(y - my_y) < tolerance);
}

