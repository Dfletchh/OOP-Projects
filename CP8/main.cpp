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

void play_game();
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
void play_game()
{
	int number_of_cards,
		player_score,
		dealer_score = 0;
	bool player_bust = false;
	Deck deck; // Declared Deck object
	Hand hand; // Declared Hand object

	string current_hand;
	char play;
	bool first_play = true;

	deck.shuffle_cards(); // shuffled deck

	cout << "Blackjack\n";
	cout << "\nDEALER'S SHOW CARD:\n";
	hand += pair<char, string>('d', deck.deal_card()); // add to dealers hand via map

	do
	{
		cout << "\nYOUR CARDS:\n";
		if (!first_play)
			hand.get_player_hand();
		hand += pair<char, string>('p', deck.deal_card()); // add to players hand via map

		if (first_play) // initilize players hand
		{
			hand += pair<char, string>('p', deck.deal_card()); // add to players
			first_play = false;
		}
		player_score = hand.get_scroe('p'); // get players score

		if (player_score > 21) // blackjack test
		{
			cout << "\nYou busted. You automatically lose\n";
			player_bust = true;
			break;
		}

		play = get_char("\nHit or stand? (h/s): ", 'h', 's'); // Input validation

	} while (play != 's'); // palyer stay instance 

	if (!player_bust)
	{
		cout << "\nDEALER'S SHOW CARDS:\n";
		while (dealer_score < 17) // dealer draws until score is over 17
		{
			hand += pair<char, string>('d', deck.deal_card()); // add to dealers hand
			dealer_score = hand.get_scroe('d'); // get dealers score
		}

		cout << "\nYOUR POINTS:" << player_score << endl
			<< "DEALER'S POINTS:" << dealer_score << endl << endl;

		if ((player_score > dealer_score) && player_score <= 21)
			cout << "You win!!!\n";

		else if ((player_score < dealer_score) && dealer_score <= 21)
			cout << "Dealer win!!!\n";

		else if (dealer_score > 21)
			cout << "Yay! The dealer busted. You win!\n";

		else if (dealer_score == player_score)
			cout << "It's a tie you win!!!\n";
	}
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