#ifndef CARD_H
#define CARD_H
#include <string>

using namespace std;

class Card{

private:
    int suit;
    int rank;
    int value;
public:
    Card();
    Card(int suit_param, int rank_param, int value_param);

    void setSuit(int suit_param);
    void setRank(int rank_param);
    void setValue(int value_param);
    int getSuit();
    int getRank();
    int getValue();

    string getSuitString();
    string getRankString();
    string operator<< ();
};
#endif