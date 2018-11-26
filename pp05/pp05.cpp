//Names: Elijah Flinders with Zackary Estabrook
//pp05 10/19/2018

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"

using namespace std;

//Write prototypes here

int getCityNames(char stringArray[150][150], int rows);


int main(int argc, char* argv[])
{

    // Catch runner code
    int result = Catch::Session().run(argc, argv);
    if (result != 0)
    {
        cout << "Some of your functions are not passing the requirements."
            << endl;
        return 1;
    }

    char cityArray[150][150] = { 0 };
    int arrayRows = 0;
    //Write your main function code here
    int getCityNames(char cityArray, int arrayRows);




    return 0;
}

//Write your functions here

int getCityNames(char stringArray[150][150], int rows)
{
    int i = 0;
    while (i < rows)
    {
        cout << "Enter city: ";
        cin.getline( stringArray[i],100);
        i++;
    }
    return rows;
}

 int findFirstCity(char stringArray[5][150], int rows)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        while (stringArray[i][j] != '\0')
        {
            stringArray[i][j] = toupper(stringArray[i][j]);
            j++;
        }
        i++;
    }
}

 int findFirstCity(char stringArray[], int rows)
 {
     int minIndex = 0;
     int i = 0;
     for (i = 0; i < rows; i++)
     {
         if (toupper(stringArray[minIndex]) > toupper(stringArray[i] ))
         {
             minIndex = i;
         }
         return minIndex;
     }
 }

 void printResult(char stringArray[5][150], int minIndex)
 {
     int i = 0;
     for (i = 0; stringArray[minIndex][i] != '\0'; i++)
     {
         toupper(stringArray[minIndex][i]);
     }   
     cout << "First City: " << stringArray[0][150]; 
 }















TEST_CASE("All uppercase cities")
{
    char names[6][100];
    strcpy_s(names[0], "RAPID CITY");
    strcpy_s(names[1], "ORLANDO");
    strcpy_s(names[2], "BUENOS AIRES");
    strcpy_s(names[3], "WALLA WALLA");
    strcpy_s(names[4], "PHILADELPHIA");
    strcpy_s(names[5], "FRANKFURT");

    int location = findFirstCity(names, 6);
    int desiredLocation = 2;
    REQUIRE(location == desiredLocation);
}

TEST_CASE("Mix of upper and lowercase cities")
{
    char names[9][100];
    strcpy_s(names[0], "Goa");
    strcpy_s(names[1], "brussels");
    strcpy_s(names[2], "baghdad");
    strcpy_s(names[3], "BOSTON");
    strcpy_s(names[4], "St. Croix");
    strcpy_s(names[5], "Santiago");
    strcpy_s(names[6], "ankara");
    strcpy_s(names[7], "Melbourne");
    strcpy_s(names[8], "Austin");

    int location = findFirstCity(names, 9);
    int desiredLocation = 6;
    REQUIRE(location == desiredLocation);

}