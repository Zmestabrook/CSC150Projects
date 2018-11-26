#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "..\catch.hpp"

//add more includes here
#include <fstream>
#include <iomanip>
#include <cctype>

using namespace std;

//add function prototypes here
bool openFiles(ifstream &input, char inputname[], ofstream &output, char outputname[]);
int readFile(double inputstuffs[][6], int size, ifstream &input);
void computeAvg(double inputstuffs[][6], int size);
void printTable( double inputstuffs[][6], int size, ofstream &output);


int main(int argc, char *argv[])
{
    double weatherstuffs[30][6];
    int rows;
    ifstream fin;
    ofstream fout;
    //Catch runner code-----------
    int result = Catch::Session().run(argc, argv);
    if (result != 0)
    {
        cout << "Some of your functions are not passing the requirements."
            << endl;
        return 1;
    }
    //----------------------------
    if (argc != 3)
    {
        cout << "Format: lab11.exe <input file name> <output file name>" << endl;
        return -1;
    }
    //Command line error message
    if (!openFiles(fin, argv[1], fout, argv[2]))
    {
        cout << "One or more files failed to open" << endl;
        return -1;
    }
    //add your main code here
    rows = readFile(weatherstuffs, 30, fin);
    computeAvg(weatherstuffs, rows);
    printTable(weatherstuffs, rows, fout);
    fin.close();
    fout.close();
    return 0;
}

//add  your functions here
bool openFiles(ifstream &input, char inputname[], ofstream &output, char outputname[])
{
    input.open(inputname);
    output.open(outputname);

    if (!input || !output)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int readFile(double inputstuffs[][6], int size, ifstream &input)
{
    int i = 0;
    while(  input >> inputstuffs[i][0] && i < size )
    {
        input >> inputstuffs[i][1];
        input >> inputstuffs[i][2];
        input >> inputstuffs[i][3];
        i++;
    }
    return i;
}

void computeAvg(double inputstuffs[][6], int size)
{
    int i = 0, j = 0;
    double avg1;
    double avg2;
    for (i = 0; i < size; i++)
    {
        avg1 = ((inputstuffs[i][0] + inputstuffs[i][1]) / 2 );
        avg2 = ((inputstuffs[i][2] + inputstuffs[i][3]) / 2);
        inputstuffs[i][4] = avg1;
        inputstuffs[i][5] = avg2;
    }
    
}

void printTable(double inputstuffs[][6], int size, ofstream &output)
{
    int i = 0;
    int j = 0;

    output << fixed << setprecision(2);
    
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < 6; j++)
            {
                output << setw(8) << inputstuffs[i][j];
            }
            output << endl;
        }
}
TEST_CASE("openFiles 1")
{
    ifstream in;
    ofstream out;
    char h[100] = "zyyznsndkglk";
    char m[100] = "DELETE__THIS_FILE.txt";
    bool result = openFiles(in, h, out, m);
    REQUIRE(result == false);
}

TEST_CASE("openFiles 2 - make sure the input files are in your project folder")
{
    ifstream in;
    ofstream out;
    char h[100] = "sept2018.txt";
    char m[100] = "DELETE_THIS_FILE.txt";
    bool result = openFiles(in, h, out, m);
    REQUIRE(result == true);
    in.close();
    out.close();
}

TEST_CASE("readFile 1")
{
    int filled = 999;
    int rows = 0;
    ifstream in;
    double data[2][6] = { {0} };
    filled = readFile(data, rows, in);
    REQUIRE(filled == 0);
}

TEST_CASE("computeAvg 1")
{
    double sumDiff = 0;
    double a[2][6] = { {1, 2, 3, 4},
                     { 5, 6, 7, 8} };

    double b[2][6] = { {1, 2, 3, 4, 1.5, 3.5},
                         {5, 6, 7, 8, 5.5, 7.5} };

    computeAvg(a, 2);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            sumDiff += (fabs(a[i][j] - b[i][j]));
        }
    }

    REQUIRE(Approx(sumDiff) == 0);
}

TEST_CASE("computeAvg 2")
{
    double sumDiff = 0;
    double a[60][6] = { {0} };

    double b[60][6] = { { 0 } };

    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            a[i][j] = i * j * 3 % 189;
            b[i][j] = i * j * 3 % 189;
        } 
        b[i][4] = (a[i][0] + a[i][1]) / 2.0;
        b[i][5] = (a[i][2] + a[i][3]) / 2.0;
        
    }

    computeAvg(a, 60);

    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            sumDiff += (fabs(a[i][j] - b[i][j]));
        }
    }

    REQUIRE(Approx(sumDiff) == 0);
}


TEST_CASE("printTable 1")
{
    double sumDiff = 0;
    ofstream out;
    double a[2][6] = { { 1, 2, 3, 4, 0 , 0 },
    { 5, 6, 7, 8, 0, 0 } };

    double b[2][6] = { { 1, 2, 3, 4, 0, 0 },
    { 5, 6, 7, 8, 0, 0 } };

    printTable(a, 2, out);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            sumDiff += (fabs(a[i][j] - b[i][j]));
        }
    }

    REQUIRE(Approx(sumDiff) == 0);
}

