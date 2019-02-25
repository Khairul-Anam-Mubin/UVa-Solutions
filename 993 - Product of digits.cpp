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

#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)

//typedef long long ll;
//typedef unsigned long long ull;
const double PI = acos(-1.0);

using namespace std;

int main()
{
    int tc,n;

    cin >> tc;

    while(tc--)
    {
        cin >> n;
        vector <int> v;
        if(n<2){
            cout << n << "\n";
            continue;
        }
        for(int i=9;i>1 && n>1;i--){
            while(n%i==0){
                v.pb(i);
                n/=i;
            }
        }
        if(n>1){
            cout << "-1\n";
            continue;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<(int)v.size();i++){
            cout << v[i];
        }
        cout << "\n";
    }

    return 0;
}
