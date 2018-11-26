#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "..\catch.hpp"

using namespace std;


// put prototypes here, you must put both in correctly before running code.
bool validColor( string , int );
int bandValue( string color);




int main(int argc, char *argv[])
{
    // define your variables here
    
    string bandNumber;
    int resistor1 = 0;
    int resistor2 = 0;
    int resistor3 = 0;
    string color1 = "";
    string color2 = "";
    string color3 = "";
    double ohms = 0;

    int result = Catch::Session().run(argc,argv);
    if( result != 0)
    {
        cout << "Some of your functions are not passing the requirements."
             << endl;
        return 1;
    }
 
    // write your code here
    cout << "Enter your three color bands: ";
    cin >> color1 >> color2 >> color3;

    resistor1 = bandValue(color1);
    resistor2 = bandValue(color2);
    resistor3 = bandValue(color3);
    if (!validColor(color1, 1))
    {
        cout << "Your first color (" << color1 << ") is invalid." << endl;
        return 0;
    }
    if (!validColor(color2, 2))
    {
        cout << "Your second color (" << color2 << ") is invalid." << endl;
        return 0;
    }
    if (!validColor(color3, 3))
    {
        cout << "Your third color (" << color3 << ") is invalid." << endl;
        return 0;
    }

    ohms = (10 * resistor1 + resistor2) * pow(10, resistor3);
    cout << fixed << setprecision(3);
    cout << "Resistor: " << ohms << " Ohms" << endl;
    

    return 0;
}



// write your functions here above the test cases;

bool validColor(string color, int bandNumber)
{
   
   
    if (bandNumber == 1 && color == "black")
    {
        return false;
    }
    if (bandNumber == 3 && (color == "gold" || color == "silver"))
    {
        return true;
    }
    if (color == "black" || color == "black" || color == "brown" || color == "red" || color == "orange"
        || color == "yellow" || color == "yellow" || color == "green" || color == "blue" || color == "violet" ||
        color == "grey" || color == "white")
    {
        return true;
    }
    return false;
} 


int bandValue(string color)
{
    if (color == "silver" )
    {
        return -2;
    }
    else if (color == "gold")
    {
        return -1;
    }
    else if (color == "black")
    {
        return 0;
    }
    else if (color == "brown")
    {
        return 1;
    }
    else if (color == "red")
    {
        return 2;
    }
    else if (color == "orange")
    {
        return 3;
    }
    else if (color == "yellow")
    {
        return 4;
    }
    else if (color == "green")
    {
        return 5;
    }
    else if (color == "blue")
    {
        return 6;
    }
    else if (color == "violet")
    {
        return 7;
    }
    else if (color == "grey")
    {
        return 8;
    }
    else if (color == "white")
    {
        return 9;
    }
    else
    {
        return 100;
    }
}

















TEST_CASE( "validColor - silver")
{
    string acolor = "silver";
    REQUIRE( validColor( acolor, 1 ) == false); 
    REQUIRE( validColor( acolor, 2 ) == false); 
    REQUIRE( validColor( acolor, 3 ) == true); 
}
TEST_CASE( "validColor - gold")
{
    string acolor = "gold";
    REQUIRE( validColor( acolor, 1 ) == false); 
    REQUIRE( validColor( acolor, 2 ) == false); 
    REQUIRE( validColor( acolor, 3 ) == true); 
}

TEST_CASE( "validColor - black")
{
    string acolor = "black";
    REQUIRE( validColor( acolor, 1 ) == false); 
    REQUIRE( validColor( acolor, 2 ) == true); 
    REQUIRE( validColor( acolor, 3 ) == true); 
}
TEST_CASE( "validColor - brown")
{
    string acolor = "brown";
    REQUIRE( validColor( acolor, 1 ) == true); 
    REQUIRE( validColor( acolor, 2 ) == true); 
    REQUIRE( validColor( acolor, 3 ) == true); 
}
TEST_CASE( "validColor - red")
{
    string acolor = "red";
    REQUIRE( validColor( acolor, 1 ) == true); 
    REQUIRE( validColor( acolor, 2 ) == true); 
    REQUIRE( validColor( acolor, 3 ) == true); 
}
TEST_CASE( "validColor - orange")
{
    string acolor = "orange";
    REQUIRE( validColor( acolor, 1 ) == true); 
    REQUIRE( validColor( acolor, 2 ) == true); 
    REQUIRE( validColor( acolor, 3 ) == true); 
}
TEST_CASE( "validColor - yellow")
{
    string acolor = "yellow";
    REQUIRE( validColor( acolor, 1 ) == true); 
    REQUIRE( validColor( acolor, 2 ) == true); 
    REQUIRE( validColor( acolor, 3 ) == true); 
}
TEST_CASE( "validColor - green")
{
    string acolor = "green";
    REQUIRE( validColor( acolor, 1 ) == true); 
    REQUIRE( validColor( acolor, 2 ) == true); 
    REQUIRE( validColor( acolor, 3 ) == true); 
}
TEST_CASE( "validColor - blue")
{
    string acolor = "blue";
    REQUIRE( validColor( acolor, 1 ) == true); 
    REQUIRE( validColor( acolor, 2 ) == true); 
    REQUIRE( validColor( acolor, 3 ) == true); 
}
TEST_CASE( "validColor - violet")
{
    string acolor = "violet";
    REQUIRE( validColor( acolor, 1 ) == true); 
    REQUIRE( validColor( acolor, 2 ) == true); 
    REQUIRE( validColor( acolor, 3 ) == true); 
}
TEST_CASE( "validColor - grey")
{
    string acolor = "grey";
    REQUIRE( validColor( acolor, 1 ) == true); 
    REQUIRE( validColor( acolor, 2 ) == true); 
    REQUIRE( validColor( acolor, 3 ) == true); 
}
TEST_CASE( "validColor - white")
{
    string acolor = "white";
    REQUIRE( validColor( acolor, 1 ) == true); 
    REQUIRE( validColor( acolor, 2 ) == true); 
    REQUIRE( validColor( acolor, 3 ) == true); 
}
TEST_CASE( "validColor - invalid colors")
{
    string acolor = "salmon";
    string anotherColor = "cyan";
    REQUIRE( validColor( acolor, 1 ) == false); 
    REQUIRE( validColor( acolor, 2 ) == false); 
    REQUIRE( validColor( acolor, 3 ) == false); 
    REQUIRE( validColor( anotherColor, 1 ) == false); 
    REQUIRE( validColor( anotherColor, 2 ) == false); 
    REQUIRE( validColor( anotherColor, 3 ) == false); 
}

TEST_CASE( "bandValue - valid colors")
{
    REQUIRE( bandValue("silver") == -2);
    REQUIRE( bandValue("gold") == -1);
    REQUIRE( bandValue("black") == 0);
    REQUIRE( bandValue("brown") == 1);
    REQUIRE( bandValue("red") == 2);
    REQUIRE( bandValue("orange") == 3);
    REQUIRE( bandValue("yellow") == 4);
    REQUIRE( bandValue("green") == 5);
    REQUIRE( bandValue("blue") == 6);
    REQUIRE( bandValue("violet") == 7);
    REQUIRE( bandValue("grey") == 8);
    REQUIRE( bandValue("white") == 9);
}
TEST_CASE( "bandValue - invalid colors")
{
    REQUIRE( bandValue("salmon") == 100);
    REQUIRE( bandValue("magenta") == 100);
    REQUIRE( bandValue("cyan") == 100);
}
