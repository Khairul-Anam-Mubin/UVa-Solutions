#include <bits/stdc++.h>

using namespace std ;

#define mx 10000001
#define mxN 2703664

vector <int> prime ;
bool isp[mxN + 5] ;
int dp[mxN + 5] ;

void sieve() {
    isp[0] = 1 ;
    isp[1] = 1 ;
    for(int i = 4 ; i <= mxN ; i += 2)
        isp[i] = 1 ;
    for(int i = 3 ; i * i <= mxN ; i += 2) {
        if(!isp[i]) {
            for(int j = i * i ; j <= mxN ; j += i + i) {
                isp[j] = 1 ;
            }
        }
    }
    prime.push_back(2) ;
    for(int i = 3 ; i <= mxN ; i += 2)
        if(!isp[i])
            prime.push_back(i) ;
}
void PreFactFactorization() {
    dp[0] = 0 ;
    dp[1] = 0 ;
    for(int i = 2 ; i <= mxN ; i++) {
        int x = i ;
        if(!isp[i]) {
            dp[i]++ ;
        }
        else {
            for(int j = 0 ; j < prime.size() && prime[j] <= x ; j++) {
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
    for(int i = 1 ; i <= mxN ; i++) {
        dp[i] += dp[i - 1] ;
    }
}
int BinarySearch(int n) {
    int left = 0 ;
    int right = mxN ;
    while(left <= right) {
        int mid = (left + right) / 2 ;
        if(dp[mid] < n) {
            left = mid + 1 ;
        }
        else 
            right = mid - 1 ;
    }
    if(dp[left] <= n)
        return left + 1 ;
    return left ;
}
int main() {
    sieve() ;
    //cout << prime.size() << "\n" ;
    PreFactFactorization() ;
    int tc ;
    scanf( "%d" , &tc) ;
    while(tc--) {
        int n ;
        scanf( "%d" ,&n) ;
        printf( "%d\n" , BinarySearch(n)) ;
    }
    return 0 ;
}
