#ifndef HAND_H
#define HAND_H
#include "card.h"
#include <string>
#include <vector>

using namespace std;

class Hand{

private:
  vector <Card> hand;
  int next;
  int total;
public:
  Card Hand::operator+= ();   
  int Hand::totalValue();
};

#endif