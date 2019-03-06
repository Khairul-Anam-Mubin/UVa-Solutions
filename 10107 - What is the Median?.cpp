#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,i=0;
    vector <int> v;

    while(cin >> x)
    {
        v.push_back(x);
        sort(v.begin(),v.end());
        if(i==0){
            cout << x << "\n";
        }
        else if(i%2){
            cout << (v[(int)(i/2)] + v[(int)(i/2)+1])/2 << "\n";
        }
        else{
            cout << v[(i/2)] << "\n";
        }
        i++;
    }

    return 0;
}
