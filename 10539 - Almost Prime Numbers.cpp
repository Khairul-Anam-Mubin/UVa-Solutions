#include <bits/stdc++.h>

using namespace std ;

#define Fout     freopen("output.txt","w",stdout)
#define mx 1000000
#define mxN 1e12
bool isp[mx + 5] ;
vector <long long> prime ;
void sieve() {
    isp[0] = 1 ;
    isp[1] = 1 ;
    for(long long i = 4 ; i <= mx ; i += 2)
        isp[i] = 1 ;
    for(long long i = 3 ; i * i <= mx ; i += 2LL) {
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
    //Fout ;
    sieve() ;
    vector <long long> vec ;
    for(long long i = 0 ; i < prime.size() ; i++) {
        for(long long j = prime[i] * prime[i] ; j <= mxN ; j *= prime[i] ) {
            vec.push_back(j) ;
        }
    }
    sort(vec.begin() , vec.end()) ;
    int tc ;
    scanf( "%d" , &tc) ;
    while(tc--) {
        long long a , b ;
        scanf( "%lld%lld" ,&a , &b) ;
        long long cnt = 0LL ;
        for(long long i = 0 ; i < vec.size() ; i++) {
            if(vec[i] >= a && vec[i] <= b)
                cnt++ ;
            if(vec[i] > b)
                break ;
        }
        printf( "%lld\n" , cnt) ;
    }
    return 0 ;
}
