#include "Card.h"
#include "Deck.h"
#include <iostream>

void Card::set_suit(std::string pass_suit)
{
	suit = pass_suit;
}
void Card::set_rank(std::string pass_rank)
{
	rank = pass_rank;
}
std::ostream& operator<< (std::ostream& out, const Card& card)
{
	out << card.rank << " of " << card.suit;
	return out;
}