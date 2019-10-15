#include <bits/stdc++.h>

using namespace std ;

#define mod 100000007
#define mx 5000000
bool isp[mx + 5] ;
vector <long long> prime ;
void sieve() {
    isp[0] = 1 ;
    isp[1] = 1 ;
    for(long long i = 4 ; i <= mx ; i += 2)
        isp[i] = 1 ;
    for(long long i = 3 ; i * i <= mx ; i += 2) {
        if(!isp[i]) {
            for(long long j = i * i ; j <= mx ; j += i + i ) {
                isp[j] = 1 ;
            }
        }
    }
    prime.push_back(2LL) ;
    for(long long i = 3 ; i <= mx ; i += 2)
        if(!isp[i])
            prime.push_back(i) ;
}
int main() {
    sieve() ;
    long long n ;
    while(scanf( "%lld" ,&n) == 1 && n ) {
        long long ans = 1LL ;
        for(int i = 0 ; i < prime.size() && prime[i] <= n ; i++) {
            long long x = n ;
            long long freq = 0LL ;
            long long temp = prime[i] ;
            while(x / temp) {
                long long tt = x / temp ;
                long long rem = x % temp + 1LL ;
                freq += rem * tt + ((tt * (tt - 1LL)) / 2LL) * temp ;
                temp *= prime[i] ;
            }
            freq++ ;
            ans = ((ans % mod) * (freq % mod)) % mod ;
        }
        printf("%lld\n", ans) ;
    }
    return 0 ;
}
