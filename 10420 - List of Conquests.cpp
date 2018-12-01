/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define pb push_back
typedef long long ll;

using namespace std;

int main()
{
    ll tc;
    string str,s;
    map <string,int> mp;
    map <string,int> :: iterator it;

    scanf("%lld",&tc);
    getchar();

    while(tc--)
    {
        cin >> str;
        getline(cin,s);

        mp[str]++;
    }
    for(it=mp.begin() ;it!=mp.end(); it++){
        cout << it->first << ' ' << it->second << "\n";
    }
    return 0;
}
