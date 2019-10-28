#include <bits/stdc++.h>

using namespace std ;

#define mx 1000000
bool isp[mx + 10] ;
vector <int> prime ;
int dsu[mx + 10] ;
void makeset(int n) {
    for(int i = 0 ; i <= n ; i++)
        dsu[i] = i ;
}
int Find(int child) {
    if(dsu[child] == child)
        return child ;
    return dsu[child] = Find(dsu[child]) ;
}
void Union(int x , int y) {
    x = Find(x) ;
    y = Find(y) ;
    if(x != y) {
        dsu[x] = y ;
    }
}
void sieve() {
    isp[0] = 1 ;
    isp[1] = 1 ;
    for(int i = 4 ; i <= mx ; i += 2)
        isp[i] = 1 ;
    for(int i = 3 ; i * i <= mx ; i += 2) {
        if(!isp[i]) {
            for(int j = i * i ; j <= mx ; j += i + i) {
                isp[j] = 1 ;
            }
        }
    }
    prime.push_back(2) ;
    for(int i = 3 ; i <= mx ; i += 2) {
        if(!isp[i])
            prime.push_back(i) ;
    }
}
void primefact(int x) {
    if(!isp[x])
        return ;
    int n = x ;
    int sq = sqrt(x) ;
    for(int i = 0 ; i < prime.size() && prime[i] <= sq ; i++) {
        if(x % prime[i] == 0) {
            while(x % prime[i] == 0) {
                x /= prime[i] ;
            }
            Union(n , prime[i]) ;
            if(!isp[x]) {
                break ;
            }
            sq = sqrt(x) ;
        } 
    }
    if(x != 1)
        Union(n , x) ;
}
int main() {
    sieve() ;
    int tc ,test = 0 ;
    scanf( "%d" ,&tc) ;
    while(tc--) {
        int n ;
        scanf( "%d",&n) ;
        int ar[n + 5] ;
        int ok = 0 ;
        for(int i = 1 ; i <= n ; i++) {
            scanf("%d",&ar[i]) ;
            ok = max(ok , ar[i]) ;
        }
        makeset(ok) ;
        for(int i = 1 ; i <= n ; i++) {
            if(ar[i] != 1) {
                primefact(ar[i]) ;
            }
        }
        int ans = 0 ;
        set <int> st ;
        for(int i = 1 ; i <= n ; i++) {
            if(ar[i] == 1) {
                ans++ ;
            }
            else {
                st.insert(Find(ar[i])) ;
            }
        }
        ans += st.size() ;
        printf("Case %d: %d\n",++test ,ans) ;
    }
    return 0 ;  
}
