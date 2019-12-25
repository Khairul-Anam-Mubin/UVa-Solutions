#include <bits/stdc++.h>
using namespace std ;

#define mxN 100000
vector <int> G[mxN + 10] ;
vector <int> order ;
bool vis[mxN + 10] ;

void Graph_clear(int n) {
    for(int i = 0 ; i <= n ; i++)
        G[i].clear() ;
    order.clear() ;
} 
void init(int n) {
    for(int i = 0 ; i <= n + 1 ; i++)
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
void dfs(int u) {
    vis[u] = 1 ;
    for(int v : G[u]) {
        if(!vis[v])
            dfs(v) ;
    }
}
int main() {
    int tc ;
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
        reverse(order.begin() ,  order.end()) ;
        int ans = 0 ;
        init(n) ;
        for(int i = 0 ; i < order.size() ; i++) {
            int v = order[i] ;
            if(!vis[v]) {
                dfs(v) ;
                ans++ ;
            }
        }
        cout << ans << "\n" ;
        Graph_clear(n) ;
    }

    return 0 ;
}
