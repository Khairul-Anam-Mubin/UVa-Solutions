#include <bits/stdc++.h>
using namespace std ;

#define mxN 1000
vector <int> G[mxN + 10] ;
vector <int> order ;
bool vis[mxN + 10] ;

void graph_clear(int nodes) {
    for(int i = 0 ; i <= nodes ; i++)
        G[i].clear() ;
    order.clear() ;
}
void init(int nodes) {
    for(int i = 0 ; i <= nodes ; i++) {
        vis[i] = 0 ;
    }
}
void dfs1(int u) {
    vis[u] = 1 ;
    for(int v : G[u]) {
        if(!vis[v]) {
            dfs1(v) ;
        }
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
    int nodes , edges ;
    while(cin >> nodes >> edges) {
        for(int i = 0 ; i < edges ; i++) {
            int u , v ;
            cin >> u >> v ;
            if(v == 0)
                continue ;
            G[u].push_back(v) ;
        }
        init(nodes) ;
        for(int i = 0 ; i <= nodes ; i++) {
            if(!vis[i])
                dfs1(i) ;
        }
        int cnt = 0 ;
        init(nodes) ;
        for(int i = order.size() - 1 ; i >= 0 ; i--) {
            int v = order[i] ;
            if(!vis[v]) {
                cnt++ ;
                dfs(v) ;
            }
        }
        cout << cnt - 1 << "\n" ;
        graph_clear(nodes) ;
    }

    return 0 ;
}
