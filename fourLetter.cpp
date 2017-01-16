#include <iostream>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <cctype>
using namespace std;


bool ifAllLetters(string str)
{
    for (int i=0; i<str.length(); i++)
    {
        if (!isalpha(str[i]))
            return false;
    }
    return true;
}

int main()
{
    ifstream f;
    f.open("/usr/share/dict/words");
    string str;
    string a;
    map< string, set<string> > words[4];
    while (f >> str)
    {
        if (!ifAllLetters(str))
            continue;
        if (str.length() == 4)
        {
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);
            for ( int i=0; i< 4; i++)
            {
                a = str;
                a.erase(i,1);
                words[i][a].insert(str);

            }
        }
    }
    string input;
    set<string> results;
    set<string>::const_iterator it;
    cout << "Enter a four letter word : ";
    while( cin >> input )
    {
        if (input.length() != 4)
        {
            cout << "wrong length!";
            continue;
        }
        int cnt = 0;
        for ( int i=0; i< 4; i++)
        {
            a = input;
            a.erase(i,1);
            for(it = words[i][a].begin(); it != words[i][a].end(); it++)
            {
                if ( (*it) != input ){
                    cout << *it << endl;
                    cnt++;
                }
            }
        }
        cout << "\nTotal " << cnt << " words. \n";
        cout << "Enter a four letter word : ";
    }
    cout << endl;
    f.close();
}













