/* 
* Auhtor: CP Group 7
* Purpose: This program analyzes the strength of a password from user input.
*          The password is classified as strong, medium, or weak and prompts
*          the user as such. 
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string strength = "Weak";
    string password;
    int num_count = 0;
    int punctuation_count = 0;
    int letter_count = 0;
    int upper_count = 0;

    cout << "Password Analyzer\n"
         << endl;
    cout << "Enter password: ";
    cin >> password;
    for (int i = 0; i < password.size(); i++)
    {
        if (isdigit(password[i]))
            num_count++;
        else if (ispunct(password[i]))
            punctuation_count++;
        else if (isalpha(password[i]))
        {
            if (isupper(password[i]))
                upper_count++;
            letter_count++;
        }
    }
    if (num_count > 3 && punctuation_count > 2 && letter_count > 7 && upper_count > 1)
        strength = "Strong";
    else if (num_count > 1 && punctuation_count > 0 && letter_count > 4 && upper_count > 0)
        strength = "Medium";
    cout << "Strength: " << strength << endl
         << endl;
    cout << "Bye!\n\n";
}