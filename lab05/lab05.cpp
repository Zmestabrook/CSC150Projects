#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    
    char ch;
    int charNum = 0;
    string password;
    int charPool = 0;
    double bitsPerChar;
    double entropyPool;
    string strength;
    bool lowerPool = false;
    bool upperPool = false;
    bool digitPool = false;
    bool blankPool = false;
    bool punctPool = false;

    cout << endl << "Enter your password/passphrase: ";
    cin.get(ch);

    while (ch != '\n')
    {
        if (lowerPool == false) 
        {
            if (islower(ch))
            {
                charPool += 26;
                lowerPool = true;
            }  
        }
        
        if (upperPool == false)
        {
            if (isupper(ch))
            {
                charPool += 26;
                upperPool = true;
            }
        }
        
        if (digitPool == false)
        {
            if (isdigit(ch))
            {
                charPool += 10;
                digitPool = true;
            }
            
        }
        
        if (blankPool == false)
        {
            if (isblank(ch))
            {
                charPool += 2;
                blankPool = true;
            }
            
        }
        
        if (punctPool == false)
        {
            if (ispunct(ch))
            {
                charPool += 32;
                punctPool = true;
            }
            
        }
       
        password += ch;
        charNum++;
        cin.get(ch);
        
    }
    
    bitsPerChar = log2(charPool);
    entropyPool = (charNum * bitsPerChar);

    if (entropyPool <= 28)
    {
        strength = "Very Weak";
    }
    else if (entropyPool <= 35)
    {
        strength = "Weak";
    }
    else if (entropyPool <= 59)
    {
        strength = "Reasonable";
    }
    else if (entropyPool <= 127)
    {
        strength = "Strong";
    }
    else
    {
        strength = "Very Strong";
    }


    cout << endl;
    cout << endl << "Password: " << password;
    cout << endl << "Character Pool: " << charPool;
    cout << fixed << setprecision(1);
    cout << endl << "Entropy bits per character: " << bitsPerChar;
    cout << endl << "Password entropy value: " << entropyPool;
    cout << endl << "Password Strength: " << strength;
    cout << endl;
    cout << endl << "Thanks for checking your password";
    cout << endl;

    return 0;
}