#include <iostream>
#include <iomanip>
#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"

//! @brief The alphabet, in all caps.
const char ALPHABET[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

using namespace std;

// Write your function prototypes here:
char rotateChar(char ch, int movement);
void rotateMessage(char messagein[], char messagout[], int movement);


/** ****************************************************************************
 * @brief The main entry point for the program.
 *
 * @details Prompts the user for a message, an amount to rotate, and the direction
 * to rotate the message. The program then rotates the given message and prints it
 * to the screen.
 *
 * @param argc The number of commandline arguments.
 * @param argv An array of commandline arguments.
 * @returns 0 if the program was successful, 1 otherwise.
 ******************************************************************************/
int main( int argc, char* argv[] )
{
    // Declare your variables here:
    char input[1024];
    char output[1024];
    int movement = 0;
    // Catch runner code
   
    int result = Catch::Session().run( argc, argv );
    if( result != 0 )
    {
        cout << "Some of your functions are not passing the REQUIREments."
            << endl;
        return 1;
    }

    // Input your message and rotate it here:
    cout << endl << "Enter your message: ";
    cin.getline(input, 1024, '\n');

    cout << endl << "Amount to rotate: ";
    cin >> movement;

    rotateMessage(input, output, movement);
    cout << output;

    return 0;
}

// Define your functions here:
char rotateChar(char ch,int movement )
{
    int position = 0;
    ch = toupper(ch);

    if (isalpha(ch))
    {
        position = ch - 'A';
        position = (position + movement + 26) % 26;
        return ALPHABET[position];
    }
    else
        return ch;
}

void rotateMessage(char messagein[], char messageout[], int movement)
{
    int i = 0;
    while (messagein[i] != '\0')
    {
        messageout[i] = rotateChar(messagein[i], movement);
        i++;
    }
    messageout[i] = '\0';
}


TEST_CASE( "example: toupper" )
{
    char input1 = 'a';
    char expected1 = 'A';

    char input2 = 'A';
    char expected2 = 'A';

    char input3 = '!';
    char expected3 = '!';

    REQUIRE( toupper( input1 ) == expected1 );
    REQUIRE( toupper( input2 ) == expected2 );
    REQUIRE( toupper( input3 ) == expected3 );
}

TEST_CASE( "example: Rotation of a single character" )
{
    REQUIRE( rotateChar( 'A', -3 ) == 'X' );
    REQUIRE( rotateChar( 'B', 2 ) == 'D' );
}

TEST_CASE( "student: Rotate a single character to the left" )
{
    REQUIRE(rotateChar('A', -3) == 'X');
    REQUIRE(rotateChar('B', 2) == 'D');

}

TEST_CASE( "student: Rotate a single character to the right" )
{
    REQUIRE(rotateChar('B', -3) == 'Y');
    REQUIRE(rotateChar('C', 2) == 'E');

}

TEST_CASE( "example: Left rotation of each character in a message" )
{
    // The plaintext to encrypt.
    char plaintext[100] = "AI";
    // The expected value of the ciphertext.
    char expected[100] = "XF";
    // A place to store the ciphertext that you encrypt.
    char ciphertext[100] = "";

    // Encrypt the given plaintext, and store the result in the ciphertext buffer.
    rotateMessage( plaintext, ciphertext, -3 );
    // Use strcmp() to compare two strings for equality!
    REQUIRE( strcmp( ciphertext, expected ) == 0 );
}

TEST_CASE( "student: Rotate a message to the left" )
{
    // The plaintext to encrypt.
    char plaintext[100] = "BC";
    // The expected value of the ciphertext.
    char expected[100] = "YZ";
    // A place to store the ciphertext that you encrypt.
    char ciphertext[100] = "";

    // Encrypt the given plaintext, and store the result in the ciphertext buffer.
    rotateMessage(plaintext, ciphertext, -3);
    // Use strcmp() to compare two strings for equality!
    REQUIRE(strcmp(ciphertext, expected) == 0);

}

TEST_CASE( "student: Rotate a message to the right" )
{
    // The plaintext to encrypt.
    char plaintext[100] = "BC";
    // The expected value of the ciphertext.
    char expected[100] = "FG";
    // A place to store the ciphertext that you encrypt.
    char ciphertext[100] = "";

    // Encrypt the given plaintext, and store the result in the ciphertext buffer.
    rotateMessage(plaintext, ciphertext, 4);
    // Use strcmp() to compare two strings for equality!
    REQUIRE(strcmp(ciphertext, expected) == 0);

}

TEST_CASE( "example: Check to see if D(E(p)) = p" )
{
    // Note that this only works if the original text is all uppercase!
    char original_plaintext[100] = "AI";
    char ciphertext[100] = "";
    char plaintext[100] = "";

    // Encrypt the message with a left rotation and store the result.
    rotateMessage( original_plaintext, ciphertext, -3 );
    // Decrypt the message with a right rotation and store the result.
    rotateMessage( ciphertext, plaintext, 3 );

    // Make sure what we got back was what we had when we started.
    REQUIRE( strcmp( plaintext, original_plaintext ) == 0 );
}

TEST_CASE( "student: Check to see if D(E(p)) = p" )
{
    // Note that this only works if the original text is all uppercase!
    char original_plaintext[100] = "AI";
    char ciphertext[100] = "";
    char plaintext[100] = "";

    // Encrypt the message with a left rotation and store the result.
    rotateMessage(original_plaintext, ciphertext, -3);
    // Decrypt the message with a right rotation and store the result.
    rotateMessage(ciphertext, plaintext, 3);

    // Make sure what we got back was what we had when we started.
    REQUIRE(strcmp(plaintext, original_plaintext) == 0);
}