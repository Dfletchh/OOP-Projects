#ifndef Deck_H
#define Deck_H

#include <string>
#include <vector>
#include "Card.h"

class Deck
{
private:
	std::vector<std::string> suit_card{ "Clubs", "Diamonds", "Hearts", "Spades" };
	std::vector<std::string> face_card{ "Jack", "Queen", "King", "Ace" };
	std::vector<Card> deck_of_cards; // Card class composition

public:
	Deck(); // constructor
	void shuffle_cards();
	std::string deal_card();
    void print_hand();
};

#endif
