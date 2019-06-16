#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll x,ll y){
    while(x != 0){
        ll temp = y % x;
        y = x;
        x = temp;
    }
    return y;
}
ll lcm(ll x , ll y){
    ll prod = x * y;
    return prod/gcd(x,y);
}
int main(){
    int tc , t = 0 ;
    cin >> tc ;
    while(tc--){
        int n ; cin >> n ;
        ll ar[n+10];
        for(int i = 0 ; i < n ; i++){
            cin >> ar[i];
        }
        ll lcmm = 1;
        for(int i = 0  ; i < n ; i++){
            lcmm = lcm(lcmm,ar[i]);
        }
        ll var = n * lcmm;
        ll sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += lcmm/ar[i];
        }
        ll gcdd = gcd(var,sum);
        cout << "Case " << ++t << ": ";
        if(gcdd == 1){
            cout << var << "/" << sum << "\n";
        }
        else{
            cout << var/gcdd << "/" << sum/gcdd << "\n";
        }
    }
    return 0;
}
