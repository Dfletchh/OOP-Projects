/* Author: Group 7
 * Purpose: The program 
*/

#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"

using namespace std;
void playAgain();

int main() {

    // Initialize variables, deck object and shuffle the deck
    char choice;
    Deck deck;
    deck.shuffle();
    vector<Hand> playerHand = deck.draw();
    vector<Hand> dealerHand = deck.draw();
    playerHand.push_back(deck.draw());
    dealerHand.push_back(deck.draw());

    // Print 2 card hand to user and ask for their action
    cout << "Blackjack\n" << endl;

    cout << "DEALER’S SHOW CARD:\n";
    dealerHand[0]<<;
    cout << endl;

    cout << "YOUR CARDS:" << endl;
    // Player loop
    do {
        
        for (int i = playerHand.begin(); i < playerHand.end(); i++)
          playerHand[i]<<;
        cout << endl;
        cout << "Hit or stand? (h/s): ";
        cin >> choice;

        if (choice == 'h') && (playerHand.totalValue() < 21)) {
            playerHand.push_back(deck.draw());
        }
        else
            cout << "Bust! You lost...\n" >> endl;
            playAgain();
            
    } while (choice == 'h');
    
    // Play dealers hand (stop on 17-21 or bust)
    cout << "DEALER'S CARDS:" << endl;
    while (dealerHand.totalValue() < 17) {
        dealerHand.push_back(deck.draw());
    }

    // Print player and dealer scores
    cout << "YOUR POINTS:\t" << playerHand.totalValue() << endl;
    cout << "DEALER POINTS:\t" << dealerHand.totalValue() << endl;

    if (dealerHand.totalValue() > 21) {
      cout << "Yay! The dealer busted. You win!\n" << endl;
    }
    else if (dealerHand.totalValue() > playerHand.totalValue()) {
      cout << "Dealer's " << dealerhand.totalValue() << " beats your "
            << playerHand.totalValue() <<". You lost!\n" << endl;
    }
    else if (playerHand.totalValue() > dealerHand.totalValue()) {
        cout << "Your " << playerHand.totalValue() << " beats the dealer's "
            << dealerHand.totalValue() <<". You win!\n" << endl;
    }
    else {
      cout << "Push. No winner.\n" << endl;
    }

    playAgain();
    return 0;
}

// Ask player if they want to play again
void playAgain() {
    char choice;
    cout << "Play again? (y/n): ";
    cin >> choice;
    
    if (choice == 'y') {
        main();
    }

    cout << "\n\nCome back soon!" << endl;
    exit(1);
}