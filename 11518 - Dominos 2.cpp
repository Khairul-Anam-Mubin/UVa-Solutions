#include <bits/stdc++.h>

using namespace std ;

int nodes , edges ;
bool vis[10010] ;
vector <int> G[10010] ;
int ans = 0 ;
void dfs(int u) {
    vis[u] = 1 ;
    for(int i = 0 ; i < G[u].size() ; i++) {
        int v = G[u][i] ;
        if(!vis[v])
            dfs(v) ;
    }
}
int main() {
    int tc ;
    scanf("%d" , &tc) ;
    while(tc--) {
        int line ;
        scanf( "%d%d%d" ,&nodes , &edges , &line) ;
        for(int i = 0 ; i < edges ; i++) {
            int u , v ;
            scanf( "%d%d" ,&u , &v) ;
            G[u].push_back(v) ;
        }
        for(int i = 0 ; i <= nodes + 1 ; i++)
            vis[i] = 0 ;
        while(line--) {
            int x ;
            scanf( "%d" ,&x) ;
            if(!vis[x])
                dfs(x) ;
        }
        int ans = 0 ;
        for(int i = 1 ; i <= nodes ; i++)
            if(vis[i])
                ans++ ;
        printf("%d\n" ,ans) ;
        for(int i = 0 ; i <= nodes + 1 ; i++)
            G[i].clear() ;
    }
    return 0 ;
}
