#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;
int readFile( char inputstuffs[][50], int size, ifstream &input );
void selectionSort( char cities[10000][50], char temp[50], int size );
void writeFile( char cities[][50], int size, ofstream &output );
int binarySearch( char cities[][50], int size, char word[] );


int main( int argc, char* argv[] )
{
    // declare variables here
    ifstream fin;
    ofstream fout;
    int search;
    int size = 0;
    char cities[10000][50];
    char temp[50];

    // check for correct startup.  At least a filename needs to be supplied
    if( argc < 2 )
    {
        cout << "Usage: lab13.exe filename "
             << "[cityname] [cityname] ... [cityname]" << endl;
        return 0;
    }
    

    // open the file, if open fails, output error message and exit program
    fin.open( argv[1] );

    if (!fin.is_open())
    {
        cout << "Unable to open input file " << argv[1] << endl;
        return 0;
    }

    // read the names of cities from file ignoring empty lines
    /*size = readFile( cities, 10000, fin );*/

    while (fin.getline( cities[size], 50 ) && size < 10000)
    {
        if (strlen( cities[size] ) > 0)
        {
            size++;
        }
    }

    // close the input file
    fin.close();


    // sort the cities by name
    selectionSort( cities, temp, size );


    // reopen the file as output
    fout.open( argv[1] );

    if (!fout.is_open())
    {
        cout << "Unable to open output file " << argv[1] << endl;
    }
    // output the cites to the file one per line

    writeFile( cities, size, fout );

    // close the output file

    fout.close();

    // if any additional arguments were provided, see if the name
    // appears in list
    for (search = 2; search < argc; search++ )
    {
        if (binarySearch( cities, size, argv[search] ) != -1)
        {
            cout << argv[search] << " is in the list" << endl;
        }
        else
        {
            cout << argv[search] << " is not in the list" << endl;
        }
    }
    // cout << "CITYNAME" << " is in the list" << endl;
    // cout << "CITYNAME" << " is not in the list" << endl;

    return 0;
}


int readFile( char inputStuffs[][50], int size, ifstream &input )
{
    int i = 0;
    while (input.getline(inputStuffs[size], 50) && i < size)
    {
        if (strlen( inputStuffs[size] ) > 0)
        {
            i++;
        }

    }
    return i;
}

void selectionSort( char cities[10000][50], char temp[50], int size )
{
    int i = 0;
    int j = 0;
    int minIndex = i;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (strcmp( cities[minIndex], cities[j] ) > 0 )
            {
                minIndex = j;
            }
        }
        strcpy( temp, cities[minIndex] );
        strcpy( cities[minIndex], cities[i] );
        strcpy( cities[i], temp );
    }
}

void writeFile( char cities[][50], int size, ofstream &output )
{
    int i = 0;
    int j = 0;
    for (i = 0; i < size; i++)
    {
        for( j = 0; j < 50; j++)
        {
        output << cities[i][j];
        }
    }
}


int binarySearch( char cities[][50], int size, char word[] )
{
    int left = 0;
    int right = size - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (strcmp( cities[mid], word ) == 0)
        {
            return mid;
        }
        if (strcmp( cities[mid], word ) < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
    
}