/* 
* Auhtor: CP Group 7
* Purpose: This program is a random number guessing game. The game can be played 
*          as many times as the user chooses and gives an unlimited amount of 
*          guess attempts. 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int upper_limit = 10;
    char answer = 'y';
    int guess;

    cout << "Guess the number!\n";
    cout << "I'm thinking of a number from 1 to " << upper_limit << "\n\n";

    while (answer == 'y' || answer == 'Y') // Loop for game repitition
    {
        // get a random number between 1 and the upper limit
        srand(time(nullptr));              // seed the rand() function
        int number = rand() % upper_limit; // number is >= 0 and < upper_limit
        ++number;                          // number is >= 1 and <= upper_limit

        int count = 1;
        while (guess != number) // loop for user guesses
        {
            cout << "Your guess: ";
            cin >> guess;

            while (guess < 1 || guess > upper_limit)
            { // check valid input
                cout << "Invalid guess. Try again.\n";
                cout << "New guess: ";
                cin >> guess;
            }
            if (guess < number)
                cout << "Too low.\n";
            else if (guess > number)
                cout << "Too high.\n";
            else
                cout << "You guessed it in " << count << " tries.\n";
            ++count;
        }
        cout << "\nWould you like to play agian (y/n): ";
        cin >> answer;
    }
    cout << "Bye!\n\n";
}