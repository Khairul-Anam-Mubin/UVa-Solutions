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
    ll tc,indx,n;
    string str;
    vector <int> v;
    map <int,string> mp;
    map <int,string> :: iterator it;

    scanf("%lld\n",&tc);
    while(tc--)
    {
        scanf("\n");
        v.clear();
        mp.clear();
        getline(cin, str);

        stringstream ss(str);
        while(ss>>n){
            v.push_back(n);
        }
        for(ll i=0 ;i<v.size(); i++){
            cin >> str;
            mp[v[i]]=str;
        }
        for(it=mp.begin();it!=mp.end();it++){
            cout << it->second << "\n";
        }
        if(tc)
            cout << "\n";
    }
    return 0;
}
