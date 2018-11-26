#include <iostream>
#include <fstream>

using namespace std;


// write your prototypes here
int readFile(int inputstuffs[], int size, ifstream &input);
void mySort(int arr[], int size);
int myFind( int arr[], int size, int target );
int countIf( int arr[], int size, int start );


int main(int argc, char* argv[])
{
    // declare variables here
    int myArray[10000], size, i, myTarget, start, myCount;
    ifstream fin;
    ofstream fout;

    // check command line arguments here
    // cout << "Usage: lab12.exe inputfile outputfile" << endl;
    if (argc != 3)
    {
        cout << "Usage: lab12.exe inputfile outputfile" << endl;
        return 0;
    }


    // open input file here, exit if it fails to open with a zero
    // cout << "Unable to open the input file " << endl;
    //openFiles(fin, argv[1], fout, argv[2], inopen, outopen);
    fin.open( argv[1] );
    if (!fin.is_open())
    {
        cout << "Unable to open the input file " << argv[1] << endl;
        fin.close();
        return 0;
    }

    fout.open( argv[2] );

    // open output file here, exit if it fails to open with a zero
    // cout << "Unable to open the output file " << endl;
    if (!fout.is_open())
    {
        cout << "Unable to open the output file " << argv[2] << endl;
        fin.close();
        fout.close();
        return 0;
    }



    // fill the array from file
    size = readFile(myArray, 10000, fin);
    // sort  the array
    mySort(myArray, size);
    // output sorted array to file 
    for (i = 0; i < size; i++)
    {
        fout << myArray[i] << endl;
    }
    
    // output number of integers, min and max range
    cout << "The file has " << size << " numbers ranging from "
          << myArray[0] << " to " << myArray[size-1] << endl << endl;
   
    cout << "Enter a number to locate (ctrl-z to quit): ";
    while (cin >> myTarget)
    {
        start = myFind( myArray, size, myTarget );
        if (start == -1)
        {
            cout << "Unable to locate the number " << myTarget << endl;
        }
        else
        {
            cout << "The number " << myTarget << " is at index " << start << endl;
            myCount = countIf( myArray, size, start );
            cout << "It appears " << myCount << " times." << endl;
            cout << endl;
        }
        cout << "Enter a number to locate (ctrl-z to quit): ";
    }
    // loop asking for input

         
        // cout << endl << "Enter a number to locate (ctrl-z to quit): ";


    // close both files.
    fin.close();
    fout.close();
    return 0;
}


// write your functions here

int readFile(int inputstuffs[], int size, ifstream &input)
{
    int i = 0;
    while (input >> inputstuffs[i] && i < size)
    {
        //input >> inputstuffs[i];
        i++;
    }
    return i;
}

void mySort( int arr[], int size )
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

int myFind( int arr[], int size, int target )
{
    int i = 0;
    while ( i < size )
    {
        if (arr[i] == target)
        {
            return i;
        }
        i++;
    }

    return -1;
}
int countIf( int arr[], int size, int start )
{
    int count = 0, i = start;
    int find = arr[start];
    if (i == -1)
    {
        return 0;
    }
    for(i = start; i < size; i++)
    {
        if (arr[i] == find) 
        {
            count++;
        }
    }
    return count;
}
