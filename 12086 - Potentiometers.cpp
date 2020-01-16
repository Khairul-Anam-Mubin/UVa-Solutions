#include <bits/stdc++.h>
using namespace std ;

#define FasterIO  ios_base :: sync_with_stdio(false); cin.tie(NULL);
#define mxN 200000
int ar[mxN + 10] ;
long long segtree[mxN * 4] ;

void Build(int cur , int left , int right) {
    if(left == right) {
        segtree[cur] = ar[left] ;
        return  ;
    }
    int mid = (left + right) / 2 ;
    Build(cur * 2 , left , mid ) ;
    Build(cur * 2 + 1 , mid + 1 , right) ;
    segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1] ;
    return ;
}
void Update(int cur , int left , int right , int pos , long long val) {
    if(pos > right || pos < left)
        return ;
    if(left >= pos && right <= pos) {
        segtree[cur] = val ;
        ar[pos] = val ;
        return ;
    }
    int mid = (left + right) / 2 ;
    Update(cur * 2 , left, mid, pos, val) ;
    Update(cur * 2 + 1 , mid + 1, right , pos , val) ;
    segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1] ;
    return ;
}
long long Query(int cur , int left , int right , int l , int r) {
    if(l > right || r < left)
        return 0 ;
    if(left >= l && right <= r) 
        return segtree[cur] ;
    int mid = (left + right) / 2 ;
    long long p1 = Query(cur * 2 , left , mid , l , r) ;
    long long p2 = Query(cur * 2 + 1 , mid + 1 , right , l , r) ;
    return (p1 + p2) ;
}
int main() {
    FasterIO
    int n ,test = 0 ;
    while(cin >> n) {
        if(n == 0)
            break ;
        if(test)
            cout << "\n" ;
        for(int i = 1 ; i <= n ; i++) 
            cin >> ar[i] ;
        Build(1 , 1 , n) ;
        string q ;
        cout << "Case " << ++test << ":\n" ;
        while(cin >> q) {
            if(q == "END")
                break;
            if(q == "S") {
                int pos ; 
                long long val ;
                cin >> pos >> val ;
                Update(1 , 1 , n , pos , val) ;
            } else if(q == "M") {
                int l  , r ;
                cin >> l >> r ;
                long long ans = Query(1 , 1 , n , l , r) ;
                cout << ans << "\n" ;
            }
        }
    }
    return 0 ;
}
