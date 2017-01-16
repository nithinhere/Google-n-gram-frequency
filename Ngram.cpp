
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char** argv){
	if (argc != 2) {
		cout << "wrong number of arguments" << endl;
		return 0;
	}
	ifstream in(argv[1]);

	map<string, set< pair<int, int > > > allWords;

	string word, skip;
	int year, freq;
	while( in >> word >> year >> freq >> skip){
		if (year >= 1800) {
			allWords[word].insert( make_pair(year, freq) );
		}

	}

	in.close();

	set< pair<int, int> >::iterator it1;
	int startYear;
	string query;

	cout << "Which word starting which year?"
	;
	while(cin>>query>>startYear){
		for(it1 = allWords[query].begin(); it1 != allWords[query].end(); it1++){
			int queryYear = it1->first;
			if ( queryYear >= startYear )
				cout << queryYear << " " << it1->second << endl;
		}
		cout << "Which word starting which year?";
	}

}
