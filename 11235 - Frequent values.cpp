#include <bits/stdc++.h>
using namespace std ;

#define INF 1e9
#define mxN 100000
int ar[mxN + 10] ;
int dp[mxN + 10] ;
vector <pair <int , int> > segtree(mxN * 4) ;  

pair <int , int> getmax(pair <int , int> &a , pair <int ,int> &b) {
    if(a.first > b.first)
        return a ;
    else if(a.first < b.first) 
        return b ;
    if(a.second >= b.second)
        return a ;
    else
        return b ;
}
void Build(int cur , int left , int right) {
    if(left == right) {
        segtree[cur] = make_pair(dp[left] , left);
        return ;
    }
    int mid = (left + right) / 2 ;
    Build(cur * 2 , left , mid) ;
    Build(cur * 2 + 1 , mid + 1 , right) ;
    segtree[cur] = getmax(segtree[cur * 2] , segtree[cur * 2 + 1]) ;
    return ;
}
pair <int , int> Query(int cur , int left , int right ,int l , int r) {
    if(l > right || r < left)
        return make_pair(-INF , 0) ;
    if(left >= l && right <= r) 
        return segtree[cur] ;
    int mid = (left + right) / 2 ;
    pair <int , int> p1 = Query(cur * 2 , left , mid , l , r) ;
    pair <int , int> p2 = Query(cur * 2 + 1 , mid + 1 , right , l , r) ;
    return getmax(p1 , p2) ;
}
int main() {
    int n , q ;
    while(scanf("%d",&n) == 1 && n != 0) {
        int q ;
        scanf("%d",&q) ;
        dp[0] = 0 ;
        for(int i = 1 ; i <= n ; i++) {
            scanf("%d",&ar[i]) ;
            dp[i] = 1 ;
        }
        for(int i = 2 ; i <= n ; i++) {
            while(i <= n && ar[i] == ar[i - 1]) {
                dp[i] = dp[i - 1] + 1 ;
                i++ ;
            }
        }
        Build(1 , 1 , n) ;
        while(q--) {
            int l , r ;
            scanf("%d%d",&l , &r) ;

            pair <int , int> ok = Query(1 , 1 , n , l , r) ;
            int ans = ok.first ;
            
            if(ar[ok.second] == ar[l - 1]) {
                ans = ok.second - (l - 1) ; 
                if(ok.second < r) {
                    ok = Query(1 , 1 , n , ok.second + 1 , r) ;
                    ans = max(ans , ok.first) ;
                }
            }
            printf("%d\n", ans) ;
        }
    }
    return 0 ;
}
