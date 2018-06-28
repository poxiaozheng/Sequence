#include "Sequence.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<cstring>

using namespace std;
vector<string>file;
string K;

Sequence::Sequence()
{
}

Sequence::~Sequence()
{
}

Sequence::Sequence(string filename)
{
	ifstream fin(filename, ios::in);
	if (!fin)
	{
		cout << "The file is not exist!";
	}
	while (!fin.eof())
	{
		string t;
		getline(fin, t);
		file.push_back(t);
	}
	file.erase(file.end() - 1, file.end());
	for (string k : file)
	{
		K.append(k);
	}
}

int Sequence::length()
{
	int totalNumber = 100 * (file.size() - 1) + (*(file.end() - 1)).length();
	return totalNumber;
}

int Sequence::numberOf(char base)
{
	return count(K.begin(), K.end(), base);
}

string Sequence::longestConsecutive()
{
	struct  priority
	{
		string B;
		int pos;
		priority(string inint)
		{
			B = inint, pos = 0;
		}

	};

	priority numA("A"); priority numT("T"); priority numC("C"); priority numG("G");
	int tempos = 0;
	while (string::npos != (tempos = K.find(numA.B)))
	{
		numA.B.append("A");
		numA.pos = tempos;
	}
	while (string::npos != (tempos = K.find(numT.B)))
	{
		numT.B.append("T");
		numT.pos = tempos;
	}
	while (string::npos != (tempos = K.find(numC.B)))
	{
		numC.B.append("C");
		numC.pos = tempos;
	}
	while (string::npos != (tempos = K.find(numG.B)))
	{
		numG.B.append("G");
		numG.pos = tempos;
	}
	numA.B.erase(0, 1);
	numT.B.erase(0, 1);
	numC.B.erase(0, 1);
	numG.B.erase(0, 1);
	priority ary[4] = { numA,numT,numC,numG };
	sort
	(
		ary, ary + 4, [](priority a, priority b)
	{
		if (a.B.length() == b.B.length())
			return a.pos < b.pos;
		else
			return a.B.length() > b.B.length();
	}
	);
	return ary[0].B;

}

string Sequence::longestRepeated()
{

	int repeatedLength = 0, offset = 0, maxLength = 0;
	char* ary1 = new char[1300000];
	char** ary2 = new char*[1300000];
	memset(ary1, 0, 1300000 * sizeof(char));
	memset(ary2, 0, 1300000 * sizeof(char*));
	copy(K.begin(), K.end(), ary1);
	for (int i = 0; i < K.length(); i++)
	{
		ary2[i] = &ary1[i];
	}
	qsort
	(
		ary2, K.size(), sizeof(char*), [](const void* a, const void* b)
	{
		return strcmp(*(char**)a, *(char**)b);
	}
	);

	for (int i = 0; i < K.length() - 1; ++i)
	{
		repeatedLength =
		(
			[](char *a, char* b)
		{
			int i = 0; 
			while (*a && (*a++ == *b++)) 
				++i;
			return i;
		}
		)
			(ary2[i], ary2[i + 1]);
		if (repeatedLength > maxLength)
		{
			maxLength = repeatedLength;
			offset = i;
		}
	}
	
	string Result = string(*(ary2 + offset), *(ary2 + offset) + maxLength);
	return Result;
}

