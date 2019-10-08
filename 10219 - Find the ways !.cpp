#include <bits/stdc++.h>

using namespace std ;

// Number of digits in nCk..
#define eps 1e-9
long long DigitNCK( long long n , long long k ) {
    double res = 0 ;
    for(long long i = n - k + 1 ; i <= n ; i++)
        res += log10(i) ;
    for(long long i = 1 ; i <= k ; i++) 
        res -= log10(i) ;
    long long ans = res + 1LL + eps ;
    return ans ;
}

int main() {
    long long n , k ;
    while(scanf("%lld%lld",&n ,&k) == 2) {
        long long ans = DigitNCK(n , k) ;
        printf("%lld\n",ans) ;
    }
    return 0 ;
}
