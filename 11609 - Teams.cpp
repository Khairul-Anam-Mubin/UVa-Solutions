#include <bits/stdc++.h>

using namespace std ;

long long mod = 1000000007 ;

long long Bigmod(long long base , long long po , long long mod) {
    if(po == 0)
        return 1 ;
    if(po % 2 == 0) {
        long long s = Bigmod(base , po / 2LL , mod) ;
        return  ((s % mod) * (s % mod)) % mod ;
    }
    return ((base % mod) * (Bigmod(base , po - 1LL , mod)) % mod) % mod ;
}
int main() {
    int tc , test = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        long long n ;
        scanf("%lld",&n) ;
        long long ans = (n * Bigmod(2LL , n - 1LL , mod)) % mod ;
        printf("Case #%d: %lld\n",++test ,ans) ;
    }
    return 0 ;
}
