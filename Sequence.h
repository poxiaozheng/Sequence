#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<string>
using namespace std;
class Sequence
{
public:
	Sequence();
	~Sequence();
	Sequence(string);
	int length();
	int numberOf(char base);	
	string longestConsecutive();
	string longestRepeated();
};

#endif
