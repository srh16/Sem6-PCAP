#include <bits/stdc++.h>
//#include <mpi.h>

using namespace std;

int main()
{
	map<string, int> wordCount;
	ifstream input;
	input.open("to_sort.txt");
	string word;
	while(input >> word)
	{
		++wordCount[word];
	}
	for(map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it)
	{
	   cout << it->first <<" : "<< it->second << endl;
	}
	return 0;
}
