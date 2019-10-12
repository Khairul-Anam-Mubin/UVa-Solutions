#include <bits/stdc++.h>

using namespace std ;

#define mx 130
vector <int> G[mx] ;
bool vis[mx] ;
int path[mx] ;
void Clear(int nodes) {
    for(int i = 0 ; i <= nodes ; i++)
        G[i].clear() ;
}
void Fill(int nodes) {
    for(int i = 0 ; i <= nodes + 1 ; i++)
        vis[i] = 0 ;
}
int dfs(int u) {
    if(vis[u])
        return 0 ;
    vis[u] = 1 ;
    for(int i = 0 ; i < G[u].size() ; i++) {
        int v = G[u][i] ;
        if(path[v] == -1 || dfs(path[v])) {
            path[v] = u ;
            return 1 ;
        }
    }
    return 0 ;
}
int main() {
    int tc ;
    scanf( "%d" , &tc) ;
    while(tc--) {
        int nodes , edges ;
        scanf( "%d%d" , &nodes , &edges) ;
        for(int i = 0 ; i < edges ; i++) {
            int u , v ;
            scanf( "%d%d" , &u , &v) ;
            G[u].push_back(v) ;
        }
        for(int i = 0 ; i <= nodes ; i++)
            path[i] = -1 ;
        int ans = 0 ;
        for(int i = 1 ; i <= nodes ; i++) {
            Fill(nodes) ;
            ans += dfs(i) ;
        }
        printf( "%d\n" ,nodes - ans) ;
        Clear(nodes) ;
    }
    return  0 ;
}
