#include <bits/stdc++.h>

using namespace std ;

#define mx 5000000
bool isp[mx + 5] ;
vector <int> prime ;
int dp[mx + 5] ;

void sieve() {
    isp[0] = 1 ;
    isp[1] = 1 ;
    for(int i = 4 ; i <= mx ; i += 2)
        isp[i] = 1 ;
    for(int i = 3 ; i * i <= mx ; i += 2 ) {
        if(!isp[i]) {
            for(int j = i * i ; j <= mx ; j += i + i ) {
                isp[j] = 1 ;
            }
        }
    }
    prime.push_back(2) ;
    for(int i = 3 ; i <= mx ; i += 2)
        if(!isp[i])
            prime.push_back(i) ;
}
void prePrimeFactorisation() {
    dp[0] = 0 ;
    dp[1] = 0 ;
    for(int i = 2 ; i <= mx ; i++) {
        int x = i ;
        if(!isp[x]) {
            dp[x] = 1 ;
            continue ;
        }
        for(int j = 0 ; j < prime.size() && prime[j] * prime[j] <= x ; j++) {
            if(x % prime[j] == 0) {
                while(x % prime[j] == 0) 
                    x /= prime[j] ;
                dp[i] += prime[j] ;
                if(!isp[x])
                    break ;
            }
        }
        if(x != 1)
            dp[i] += x ;
        if(!isp[dp[i]])
            dp[i] = 1 ;
        else
            dp[i] = 0 ;
    }
    for(int i = 1 ; i <= mx ; i++)
        dp[i] += dp[i - 1] ;
    //for(int i = 1 ; i <= 100 ; i++)
        //cout << i << " " << dp[i] << "\n" ;
}
int main() {
    sieve() ;
    prePrimeFactorisation() ;
    int a , b ;
    while(scanf( "%d" , &a) == 1 && a) {
        scanf( "%d" , &b) ;
        printf( "%d\n" , dp[b] - dp[a - 1]) ;
    }
    return 0 ;
}
