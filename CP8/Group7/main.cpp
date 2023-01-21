/*
 Participants:
 	Peter Garas, Dean Fletcher, Dongni Jiang, Daniel Paulius, Alessandro D'Alessandro

 Description: this code plays a game of blackjack with the user
 */
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <limits>
#include "Deck.h"
#include "Hand.h"

using namespace std;

int play_game();
char get_char(string prompt, char param1, char param2, bool add_blank_line = true);

int main()
{
	char input;
	do
	{
		play_game();
		input = get_char("\nPlay again? (y/n): ", 'y', 'n'); // Input validation to continue
	} while (input != 'n');

	cout << "Come back soon!\n";
	return 0;
}
// Function for Game logic // 
int play_game() {

    // Initialize variables
	int number_of_cards,
		player_score,
		dealer_score = 0;
	bool first_play = true, player_bust = false;
	Deck deck; // Declared Deck object
	Hand hand; // Declared Hand object
	string current_hand;
	char play;

	deck.shuffle_cards(); // shuffled deck
    cout << "Blackjack\n";

    cout << "\nDEALER'S SHOW CARD:\n";
    hand += pair<char, string>('d', deck.deal_card()); // add to dealers hand via map
    cout << endl;

    do {
		cout << "YOUR CARDS:\n";
		if (!first_play)
			hand.get_player_hand();
		hand += pair<char, string>('p', deck.deal_card()); // add to players hand via map

		if (first_play) // initilize players hand
		{
			hand += pair<char, string>('p', deck.deal_card()); // add to players
			first_play = false;
		}
		player_score = hand.get_score('p'); // get players score

		if (player_score > 21) // blackjack test
		{
			cout << "\nYou busted. You automatically lose\n";
			return 0;
		}

		play = get_char("\nHit or stand? (h/s): ", 'h', 's'); // Input validation

	} while (play != 's'); // player stay instance 

    // Print dealer's hand
    cout << "DEALER'S CARDS:\n";
    hand.get_dealer_hand();

    while (dealer_score < 17) // dealer draws until score is 17 or higher
    {
        hand += pair<char, string>('d', deck.deal_card()); // add to dealers hand
        dealer_score = hand.get_score('d'); // get dealers score
    }

    // Print the points of both players
    cout << "\nYOUR POINTS:" << player_score << endl
        << "DEALER'S POINTS:" << dealer_score << endl << endl;

    // Print the game outcome
    if (dealer_score > 21)
        cout << "Yay! The dealer busted. You win!\n";
    else if (player_score > dealer_score)
        cout << "You win!!!\n";
    else if (player_score < dealer_score)
        cout << "Dealer wins...\n";
    else 
        cout << "Push. Tie game!";
    
    return 0;
}

// Input validation function //
char get_char(string prompt, char param1, char param2, bool add_blank_line) 
{
    char choice = 'n';
    cout << prompt;
    cin >> choice;
    while (choice != param1 && choice != param2) {  // Validation loop
        cout << "Invalid entry!" << endl << prompt;
        cin >> choice;
    }
    if (add_blank_line)
        cout << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear stream
    return choice;
}
