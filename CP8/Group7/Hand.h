#ifndef HAND_H
#define HAND_H

#include <vector>
#include <map>
class Hand
{
private:
	std::multimap<char, std::string> hands;

public:
	void operator += (std::pair<char, std::string> pass_hand);
	int get_score(char dealer_player);
	void get_player_hand();
    void get_dealer_hand();
};

#endif // !HAND_H
