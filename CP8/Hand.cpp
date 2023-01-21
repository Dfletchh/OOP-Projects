#include "Hand.h"
#include <sstream>
#include <iostream>
#include <string>

void Hand::operator += (std::pair<char, std::string> pass_hand)
{
	hands.insert(pass_hand); // add to map w/ key
}
int Hand::get_scroe(char dealer_player)
{
	std::stringstream ss;
	std::string test;
	int result = 0,
		temp;
	for (auto i : hands)
	{
		ss.clear();
		if (i.first == dealer_player)
		{
			test = i.second;
			ss.str(test);
			if (ss >> temp)
			{
				result += temp;
				continue;
			}
			else
				result += 10;
		}
	}
	return result;
}
void Hand::get_player_hand()
{
	for (auto i : hands)
		if (i.first == 'p')
			std::cout << i.second << '\n';
}