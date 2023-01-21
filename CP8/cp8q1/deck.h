#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <string>

using namespace std;

class Deck{

private:
    Card cards[52];
    int next;
public:
    Deck();
    string toString();
    Card getNext();
    int getRemainingCards();
    void shuffle();
};
#endif