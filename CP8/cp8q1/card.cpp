#include "card.h"
#include <string>

// Empty Constructor
Card::Card(){
    suit = 0;
    rank = 0;
    value = 0;
}

// Default Constructor
Card::Card(int suit_param,int rank_param, int value_param) {
    suit = suit_param;
    rank = rank_param;
    value = value_param;
}

// Get functions
int Card::getSuit() {
    return suit;
}
int Card::getRank() {
    return rank;
}
int Card::getValue() {
    return value;
}

// Set functions
void Card::setSuit(int suit_param) {
    suit = suit_param;
}
void Card::setRank(int rank_param){
    rank = rank_param;
}
void Card::setValue(int value_param){
    value = value_param;
}

// Returns the suit of the card
string Card::getSuitString() {
    if(suit == 0)
        return "Clubs";
    else if(suit == 1)
        return "Diamonds";
    else if(suit == 2)
        return "Hearts";
    return "Spades";
}

// Returns the rank of the card
string Card::getRankString(){
    string ranks[]={"", "Ace", "2", "3", "4", "5", "6", "7", "8", 
            "9", "10", "Jack", "Queen", "King"};
    return ranks[rank];
}

// Prints the card to the console
string Card::operator<< (){
    return getRankString() + " of " + getSuitString() + "\n";
}