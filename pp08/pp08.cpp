// christian.dyson@mines.sdsmt.edu
//zackary butz

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// declare your structure type here.
struct states
{
    char statename[50];
    char capital[50];
    char bird[50];
    char flower[50];
    char nickname[50];
};


// place function prototypes below the structure type declaration.
void sortStates( states arr[], int size );


int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    // declare your variables here
    // create an array of 50 of whatever your structure type is
    states state[50];
    ifstream fin;
    ofstream fout;

    // handle command line count
    //    cout << "Usage: pp08.exe inputfile outputfile" << endl;
    if (argc != 3)
    {
        cout << "Usage: pp08.exe inputfile outputfile" << endl;
        return 0;
    }

    // handle input file  
    //    cout << "Unable to open the input file " << "FILENAME" << endl;
    fin.open( argv[1] );

    if (! fin.is_open())
    {
        cout << "Unable to open the input file " << argv[1] << endl;
        fin.close();
        return 0;
    }

    // handle output file
    //    cout << "Unable to open the output file " << "FILENAME" << endl;
    fout.open( argv[2] );
    
    if (! fout.is_open())
    {
        cout << "Unable to open the output file " << argv[2] << endl;
        fout.close();
        fin.close();
        return 0;
    }
   
    // read the data into your array.  Assume 50 items
    for( i=0; i<50; i++)
    {
        fin.getline( state[i].statename, 50, ',' );
        fin.getline( state[i].capital, 50, ',' );
        fin.getline( state[i].bird, 50, ',' );
        fin.getline( state[i].flower, 50, ',' );
        fin.getline( state[i].nickname, 50);
    }

    // sort your data
    sortStates( state, 50 );

    // output your data to the file. Assume 50 
    for( i=0; i<50; i++)
    {
        fout << state[i].statename << " - " << state[i].capital << endl;
        fout << "     " << state[i].nickname << endl;
        fout << "     " << state[i].bird << " & " << state[i].flower;
        fout << endl << endl;
    }

 
    //remember to close files when finished!

    fin.close();
    fout.close();

   
    return 0;
}

void sortStates( states arr[], int size )
{
    int i = 0;
    int j = 0;
    for (i = 0; i < size; i++)
    {
        int minIndex = i;
        for (j = i + 1; j < size; j++)
        {
            if (strcmp( arr[minIndex].statename, arr[j].statename ) > 0)
            {
                minIndex = j;
            }
        }
        swap( arr[minIndex], arr[i] );
    }
}