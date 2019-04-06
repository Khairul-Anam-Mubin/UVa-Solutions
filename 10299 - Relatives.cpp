#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
   ll n;
   while(cin >> n)
   {
       if(n == 0)
            break;
        if(n == 1){
            cout << "0\n";
            continue;
        }
       ll coprime = n;

       for(ll i = 2 ; i*i <= n ; i++){
            if(n % i == 0){
                while(n % i == 0)
                    n/=i;
                coprime -= (coprime/i);
            }
       }
       if(n > 1)
            coprime -= (coprime/n);
       cout << coprime << "\n";
   }

    return 0;
}
