#include "deck.h"
#include <string>
#include <stdlib.h> 
#include <time.h>

Deck::Deck() {

    // Initialize variables
    int i, j, k = 0, next = 0;

    // Add suit, rank, and value to every card in the deck
    for(i = 0; i < 4; i++) {
        for(j = 1; j <= 13; j++) {
            cards[k].setSuit(i);
            cards[k].setRank(j);
            if (j == 1) {
                cards[k++].setValue(11);
            }
            else if (j > 10) {
                cards[k++].setValue(10);
            }
            else
                cards[k++].setValue(j);
        }
    }
}

// Stores every card in a 52 card deck
string Deck::toString(){
        string s = "";
        int i, j, k = 0;
        for(i=0; i < 4; i++)
            for(j=0; j < 13 ;j++)
                s += cards[k++].toString();
        return s;
}

// Returns the next card in the deck
Card Deck::getNext() {   
    return cards[next++];
}

// Returns how many cards still left in deck
int Deck::getRemainingCards() {
    return 52 - next;
}

// Shuffles the deck
void Deck::shuffle() {

    // Initialize variables
    int i, j, k;
    Card temp;
    next = 0; // Reset the cards that have been reveled

    // Randomizes the deck
    srand(time(0)); 
    for(i = 0; i < 1000; i++) {       
        j = rand() % 51;
        k = rand() % 51;
        temp = cards[j];
        cards[j] = cards[k];
        cards[k] = temp;     
    }
}
        