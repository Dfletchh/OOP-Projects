#ifndef Card_H
#define Card_H

#include <string>

class Card
{
private:
	std::string suit,
		rank;

public:
	void set_suit(std::string pass_suit);
	void set_rank(std::string pass_rank);
	friend std::ostream& operator<< (std::ostream&, const Card&);

};

#endif
