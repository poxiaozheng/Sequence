#include<iostream>
#include<fstream>
#include<time.h>
#include"Sequence.h"
using namespace std;
int main()
{
	clock_t begin,end;
	begin=clock();
	Sequence A("dna.txt");
	cout << "The total length:" << A.length() << endl;
	cout << "The number of A:" << A.numberOf('A') << endl;
	cout << "The number of T:" << A.numberOf('T') << endl;
	cout << "The number of C:" << A.numberOf('C') << endl;
	cout << "The number of G:" << A.numberOf('G') << endl;
	cout << "The longConsecutive:" << A.longestConsecutive() << endl;
	cout << "The longestRepeated:" << A.longestRepeated() << endl;
	end=clock();
	cout<<(double)(end-begin)/(CLOCKS_PER_SEC)<<endl;
	return 0;
}
