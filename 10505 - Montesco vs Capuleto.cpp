#include <bits/stdc++.h>
using namespace std ;

#define mxN 200
set <int> g[mxN + 10] ; 
int color[mxN + 10] ;
int flag , cnt1 , cnt2 ;
void dfs(int u , int col) {
    color[u] = col ;
    for(int v : g[u]) {
        if(color[v] == 0 && col == 1) {
            dfs(v , 2) ;
            cnt2++ ;
        } else if(color[v] == 0 && col == 2) {
            dfs(v , 1) ;
            cnt1++ ;
        } else if(color[v] == color[u]) {
            flag = 0 ;
        }
    }
}
int main() {
    int tc ;
    cin >> tc ;
    while(tc--) {
        int n ;
        cin >> n ;
        for(int u = 1 ; u <= n ; u++) {
            int x ;
            cin >> x ;
            while(x--) {
                int v ;
                cin >> v ;
                if(v <= n) {
                    if(g[u].find(v) == g[u].end()) {
                        g[u].insert(v) ;
                    }
                    if(g[v].find(u) == g[v].end()) {
                        g[v].insert(u) ;
                    }
                }
            }
        }
        /*
        for(int i = 1 ; i <= n ; i++) {
            cout << i << " : " ;
            for(int j : g[i]) {
                cout << j << " -> " ;
            }
            cout << "\n" ;
        }
        */
        for(int i = 1 ; i <= n ; i++)
            color[i] = 0 ;

        int ans = 0 ;
        for(int i = 1 ; i <= n ; i++) {
            cnt1 = 0 ;
            cnt2 = 0 ;
            flag = 1 ;
            if(color[i] == 0) {
                dfs(i , 1) ;
                cnt1++ ;
                if(flag) {
                    ans += max(cnt1 , cnt2) ;
                }
            }
        }
        cout << ans << "\n" ;
        for(int i = 1 ; i <= n ; i++)
            g[i].clear() ;
    }

    return 0 ;
}
