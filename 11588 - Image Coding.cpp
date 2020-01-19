#include <bits/stdc++.h>
using namespace std ;
 
#define FasterIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define precision(a) cout << fixed << setprecision(a) 
#define mxN 100000
template <typename T> T Abs(T a) {
    if(a < 0) return -a;
    else return a;
}

int main() {
    FasterIO
    int tc ,test = 0  ;
    cin >> tc ;
    while(tc--) {
        int r , c , m , n ;
        cin >> r >> c >> m >> n ;
        char g[r + 1][c + 1] ;
        map <char, int> mp ;
        for(int i = 1 ; i <= r ; i++) {
            for(int j = 1 ; j <= c ; j++) {
                cin >> g[i][j] ;
                mp[g[i][j]]++ ;
            }
        }
        vector <int> vec ;
        for(auto it : mp) {
            vec.push_back(it.second) ;
        }
        sort(vec.rbegin() , vec.rend()) ;
        int ok = vec[0] ;
        long long ans = 0 ;
        for(int i = 0 ; i < vec.size() ; i++) {
            if(ok == vec[i]) {
                ans += vec[i] * m ;
            } else {
                ans += vec[i] * n ;
            }
        }
        cout << "Case " << ++test << ": " ;
        cout << ans << "\n" ;
    }

    return 0 ;
}
