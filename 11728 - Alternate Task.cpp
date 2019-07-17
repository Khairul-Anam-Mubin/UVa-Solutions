#include <bits/stdc++.h>
using namespace std ;
int main() {
    int ar[2001] ;
    for(int i = 0 ; i <= 2000 ; i++)
        ar[i] = 0 ;
    for(int i = 1 ; i <= 2000 ; i++) {
        int sq = sqrt(i) ;
        for(int j = 1; j <= sq ; j++) {
            if(i % j == 0) {
                ar[i] += j ;
                ar[i] += (i / j) ;
            }
        }
        if(sq * sq == i)
            ar[i] -= sq ;
    }
    int dp[100001] ;
    for(int i = 0 ; i <= 100000 ; i++)
        dp[i] = -1 ;
    for(int i = 1 ; i <= 1200 ; i++)
        dp[ar[i]] = max(i , dp[ar[i]]) ;
    int n ,tc = 0;
    while(cin >> n && n) {
        printf("Case %d: ",++tc) ;
        cout << dp[n] << "\n" ;
    }
    return 0 ;
}
