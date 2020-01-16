#include <bits/stdc++.h>
using namespace std ;

#define FasterIO  ios_base :: sync_with_stdio(false); cin.tie(NULL);
#define mxN 100000
int ar[mxN + 10] ;
int segtree[mxN * 4] ;

int Convert_sign(int x) {
    if(x < 0)
        return -1 ;
    if(x > 0)
        return 1 ;
    return 0 ;
}
void Build(int cur , int left , int right) {
    if(left == right) {
        segtree[cur] = ar[left] ;
        return  ;
    }
    int mid = (left + right) / 2 ;
    Build(cur * 2 , left , mid ) ;
    Build(cur * 2 + 1 , mid + 1 , right) ;
    segtree[cur] = segtree[cur * 2] * segtree[cur * 2 + 1] ;
    return ;
}
void Update(int cur , int left , int right , int pos , int val) {
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
    segtree[cur] = segtree[cur * 2] * segtree[cur * 2 + 1] ;
    return ;
}
int Query(int cur , int left , int right , int l , int r) {
    if(l > right || r < left)
        return 1 ;
    if(left >= l && right <= r) 
        return segtree[cur] ;
    int mid = (left + right) / 2 ;
    int p1 = Query(cur * 2 , left , mid , l , r) ;
    int p2 = Query(cur * 2 + 1 , mid + 1 , right , l , r) ;
    return (p1 * p2) ;
}
int main() {
    FasterIO
    int n , q ;
    while(cin >> n >> q) {
        for(int i = 1 ; i <= n ; i++) {
            cin >> ar[i] ;
            ar[i] = Convert_sign(ar[i]) ;
        }
        Build(1 , 1 , n) ;
        string str ;
        while(q--) {
            char ch ; cin >> ch ;
            if(ch == 'C') {
                int pos , val ;
                cin >> pos >> val ;
                val = Convert_sign(val) ;
                Update(1 , 1 , n , pos , val) ;
            } else if(ch == 'P') {
                int l , r ;
                cin >> l >> r ;
                int ans = Query(1 , 1 , n , l , r) ;
                if(ans == 0)
                    str.push_back('0') ;
                else if(ans == -1)
                    str.push_back('-') ;
                else if(ans == 1) 
                    str.push_back('+') ;
            }
        }
        cout << str << "\n" ;
    }

    return 0 ;
}
