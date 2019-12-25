#include <bits/stdc++.h>
using namespace std ;

#define mxN 10000
vector <int> G[mxN + 10] ;
vector <int> order ;
bool vis[mxN + 10] ;

void Graph_clear(int n ) {
    for (int i = 0; i <= n ; ++i ) {
        G[i].clear() ;
    }
    order.clear() ;
}
void init(int n) {
    for(int i = 0 ; i <= n ; i++)
        vis[i] = 0 ;
}
void dfs1(int u) {
    vis[u] = 1 ;
    for(int v : G[u]) {
        if(!vis[v])
            dfs1(v) ;
    }
    order.push_back(u) ;
}
void dfs2(int u) {
    vis[u] = 1 ;
    for(int v : G[u]) {
        if(!vis[v])
            dfs2(v) ;
    }
}
int main() {
    int tc ,test = 0 ;
    cin >> tc ;
    while(tc--) {
        int n , m ;
        cin >> n >> m ;
        for(int i = 0 ; i < m ; i++) {
            int u , v ;
            cin >> u >> v ;
            G[u].push_back(v) ;
        }
        init(n) ;
        for(int i = 1 ; i <= n ; i++) {
            if(!vis[i])
                dfs1(i) ;
        }
        init(n) ;
        int ans = 0 ;
        for(int i = order.size() - 1 ; i >= 0 ; i--) {
            int u = order[i] ;
            if(!vis[u]) {
                dfs2(u) ;
                ans++ ;
            }
        }
        cout << "Case " << ++test << ": " << ans << "\n" ;
        Graph_clear(n) ;
    }

    return 0 ;
}
