#define CATCH_CONFIG_RUNNER
#include "..\catch.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// functions given to you already written.
bool isPrime( int n );
bool isSorted( int arr[], int size );
void mySort(int arr[], int size);
bool openFiles(ifstream &input, char inputname[], ofstream &output, char outputname[], bool &inopen, bool &outopen);
// place your prototype here.


int main( int argc, char* argv[] )
{
    // declare your variables here
    int i, size = 0;
    ifstream fin; //argv[1]
    ofstream fout; //argv[2]
    bool inOpen, outOpen;
    int inArray[100];

    /*   DO NOT EDIT THIS SECTION AT ALL  */
    int result = Catch::Session().run( );
    if ( result != 0 )
    {
        cout << "Some of your functions are not passing the requirements."
             << endl;
        return 1;
    }
    /*   Start coding below this line   */

    // handle command line arguments using argc
    // cout << "Usage: pp07.exe inputfile outputfile" << endl;
    if (argc != 3)
    {
        cout << "Usage: pp07.exe inputfile outputfile" << endl;
        return 0;
    }

    openFiles(fin, argv[1], fout, argv[2], inOpen, outOpen);
    // try opening the input file then test for successful open
    // cout << "Unable to open the input file " << endl;
    if (inOpen == false)
    {
        cout << "Unable to open the input file " << argv[1] << endl;
        return 0;
    }
    // try opening the output file then test for successful open
    // cout << "Unable to open sthe output file " << endl;
    if (outOpen == false)
    {
        cout << "Unable to open the output file "<< argv[2] << endl;
        return 0;
    }
    // read the data into the array
    for (i = 0; i < 100; i++)
    {
        fin >> inArray[i];
        size++;
    }
    // sort the array
    mySort(inArray, size);

    // output prime number to the file
    for (i = 0; i < size; i++)
    {
        if (isPrime(inArray[i]))
        {
            fout << inArray[i] << endl;
        }
    }
    // close both files.
    fin.close();
    fout.close();
    return 0;
}


//write your is sorted function here

bool openFiles(ifstream &input, char inputname[], ofstream &output, char outputname[], bool &inopen, bool &outopen)
{
    input.open(inputname);

    if (!input.is_open() )
    {
        inopen = false;
        input.close();
        return false;
    }

    output.open(outputname);
    if( !output.is_open() )
    {
        input.close();
        outopen = false;
        return false;
    }
    inopen = true;
    outopen = true;
    return true;
}

void mySort(int arr[], int size)
{
    int i, j = 0;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}





bool isPrime( int n )
{
    int i;
    int upper;

    if( n < 2 )
    {
        return false;
    }
    if( n > 2 && n % 2 == 0 )
    {
        return false;
    }

    upper = static_cast<int>( sqrt( n ) ) + 2;

    for( i = 3; i < upper; i += 2 )
        if( n % i == 0 )
        {
            return false;
        }

    return true;
}

bool isSorted( int arr[], int size )
{
    int i;
    for( i = 0; i < size - 1; i++ )
    {
        if( arr[i] > arr[i + 1] )
        {
            return false;
        }
    }
    return true;
}

TEST_CASE( "Sorting" )
{
    int a[10] = {3, 5, 4, 6, 7, 8, 10, 21, 32, 1};
    int b[5] = {10, 19, 14, 3, 81};
    int c[5] = { -20, -30, -40, -21, -38 };

    int d[10] = { 10, 34,67,56,51,52,98,67,34,39};
    int e[5] = {45, 56,98, 15, 1};
    int f[5] = {67, 78, -67,0,-78};

    mySort( a, 10 );
    REQUIRE( isSorted( a, 10 ) == true );

    mySort( b, 5 );
    REQUIRE( isSorted( b, 5 ) == true );

    mySort( c, 5 );
    REQUIRE( isSorted( c, 5 ) == true );

    mySort( d, 10 );
    REQUIRE( isSorted( d, 10 ) == true );

    mySort( e, 5 );
    REQUIRE( isSorted( e, 5 ) == true );

    mySort( f, 5 );
    REQUIRE( isSorted( f, 5 ) == true );


}
