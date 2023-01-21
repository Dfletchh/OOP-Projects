#include "hand.h"
#include <string>
#include <stdlib.h> 

int next = 0;

Card Hand::operator+= () {   
    return hand[next++];
}
int Hand::totalValue() {
  for (Card it : hand){
      total += it.getValue();
  }
  return total;
}