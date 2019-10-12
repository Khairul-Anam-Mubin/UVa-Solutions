#include <bits/stdc++.h>

using namespace std ;

#define mx 100000
bool isp[mx + 5] ;
vector <long long> prime ;
void sieve() {
    isp[0] = 1 ;
    isp[1] = 1 ;
    for(long long i = 4 ; i <= mx ; i += 2)
        isp[i] = 1 ;
    for(long long i = 3 ; i * i <= mx ; i += 2) {
        if(!isp[i]) {
            for(long long j = i * i ; j <= mx ; j += i + i) {
                isp[j] = 1 ;
            }
        }
    }
    prime.push_back(2LL) ;
    for(long long i = 3 ; i <= mx ; i += 2 )
        if(!isp[i]) 
        prime.push_back(i) ;
}
long long SOD(long long p) {
    long long ans = 1 ;
    /*long long n = 1 ;
    for(long long i = 1 ; i < p ; i++) {
        n *= 2LL ;
        ans += n ;
    }
    long long x = pow(2LL , p) ;
    x-- ;
    */
    long long x = pow(2LL , p - 1LL) * (pow(2LL , p) - 1LL) ;
    long long n = x ;
    long long sq = sqrt(x) ;
    for(int i = 0 ; i < prime.size() && prime[i] <= sq ; i++) {
        if(x % prime[i] == 0 ) {
            long long temp = 1 ;
            long long pw = 1 ;
            while(x % prime[i] == 0) {
                x /= prime[i] ;
                pw *= prime[i] ;
                temp += pw ;
            }
            ans *= temp ;
            sq = sqrt(x) ;
        }
    }
    if(x != 1) {
        ans *= (x + 1LL) ;
    }
    return ((ans - n) == n) ;
}
int main() {
    sieve() ;
    int tc ;
    scanf("%d",&tc) ;
    for(int tes = 1 ; tes <= tc ; tes++) {
        long long p ;
        if(tes == tc) {
            scanf("%lld" ,&p) ;
        }
        else {
            scanf("%lld," ,&p) ;
        }
        long long ans = SOD(p) ;
        if(ans == 1) {
            printf("Yes\n") ;
        }
        else {
            printf("No\n") ;
        }
    }

    return 0 ;
}
