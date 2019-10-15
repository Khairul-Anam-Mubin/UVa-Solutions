#include <bits/stdc++.h>

using namespace std ;

#define Fout     freopen("output.txt","w",stdout)
#define mx 10000001
#define mxN 2703664

bool isp[mx + 5] ;
long long dp[mxN + 5] ;
long long pre[mx + 5] ;
vector <long long> prime ;

void sieve() {
    isp[0] = 1 ;
    isp[1] = 1 ;
    for(long long i = 4 ; i <= mxN ; i += 2)
        isp[i] = 1 ;
    for(long long i = 3LL ; i * i <= mxN ; i += 2LL) {
        if(!isp[i]) {
            for(long long j = i * i ; j <= mxN ; j += i + i) {
                isp[j] = 1 ;
            }
        }
    }
    prime.push_back(2LL) ;
    for(long long i = 3LL ; i <= mxN ; i += 2LL)
        if(!isp[i])
            prime.push_back(i) ;
}
int main() {
    //Fout ;
    sieve() ;
    dp[0] = 0 ;
    dp[1] = 0 ;
    for(long long i = 2 ; i <= mxN ; i++) {
        long long x = i ;
        if( !isp[x] ) {
            dp[x]++ ;
        }
        else {
            for(long long j = 0 ; j < prime.size() && prime[j] <= x ; j++) {
                if(x % prime[j] == 0) {
                    while(x % prime[j] == 0) {
                        x /= prime[j] ;
                        dp[i]++ ;
                    }
                    if(!isp[x])
                        break ;
                }
            }
            if(x != 1)
                dp[i]++ ;
        }
    }
    for(int i = 0 ; i <= mx ; i++)
        pre[i] = -1 ;
    for(int i = 0 ; i <= mxN ; i++) {
        dp[i] += dp[i - 1] ;
        pre[dp[i]] = i ;
    }
    pre[0] = 0 ;
    long long n , tc = 0 ;
    while(scanf( "%lld" , &n) == 1) {
        if(n < 0)
            break ;
        if(pre[n] == -1) {
            printf( "Case %lld: Not possible.\n" ,++tc ) ;
        }
        else {
            printf( "Case %lld: %lld!\n" ,++tc , pre[n] ) ;
        }
    }
    return 0 ;
}
