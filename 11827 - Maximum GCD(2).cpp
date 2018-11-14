/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,i,n,gcd,j;
    string str;
    vector <int> v;

    cin >> t;
    getchar();

    while(t--)
    {
        getline(cin,str);

        stringstream ss(str);

        while(ss>>n){
            v.push_back(n);
        }
        gcd=0;
        for(i=0;i<v.size()-1;i++){
            for(j=i+1;j<v.size();j++){
                gcd=max(gcd,__gcd(v[i],v[j]));
            }
        }
        cout << gcd << endl;
        v.clear();
    }

    return 0;
}
