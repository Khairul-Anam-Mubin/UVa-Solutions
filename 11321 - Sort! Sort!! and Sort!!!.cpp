#include <bits/stdc++.h>
using namespace std ;
 
#define FasterIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define precision(a) cout << fixed << setprecision(a) 
#define mxN 100000
template <typename T> T Abs(T a) {
    if(a < 0) return -a;
    else return a;
}

struct node {
    long long val , mod ;
} ;
bool cmp(node a , node b) {
    if(a.mod != b.mod)
        return a.mod < b.mod ;
    else {
        int x = (abs(a.val) % 2) + (abs(b.val) % 2) ;
        if(x == 1) {
            return (abs(a.val) % 2)? 1 : 0 ;
        } else if(x == 2) {
            return a.val > b.val ;
        } else if(x == 0) {
            return a.val < b.val ;
        }
    }
}
int main() {
    FasterIO
    int n , m ;
    while(cin >> n >> m) {
        cout << n << " " << m << "\n" ;
        if(n == 0 && m == 0) 
            break ;
        node ar[n + 5] ;
        for(int i = 0 ; i < n ; i++) {
            cin >> ar[i].val ;
            ar[i].mod = ar[i].val % m ;
        }
        sort(ar , ar + n , cmp) ;
        for(int i = 0 ; i < n ; i++) 
            cout << ar[i].val << "\n" ;
    }
    return 0 ;
}
