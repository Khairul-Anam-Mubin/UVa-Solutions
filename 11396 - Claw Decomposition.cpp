#include <bits/stdc++.h>
using namespace std ;

#define mxN 300
vector <int> G[mxN + 10] ;
int color[mxN + 10] ;
bool flag ;
void dfs(int u , int col) {
    color[u] = col ;
    for(int v : G[u]) {
        if(col == 1 && color[v] == 0) {
            dfs(v , 2) ;
        } else if(col == 2 && color[v] == 0) {
            dfs(v , 1) ;
        } else if(color[v] == color[u]){
            flag = 0 ;
            return ;
        }
    }
    return ;
}
int main() {
    int n ;
    while(cin >> n && n != 0) {
        int u , v ;
        while(cin >> u >> v) {
            if( u == 0 && v == 0)
                break ;
            G[u].push_back(v) ;
            G[v].push_back(u) ;
        }
        for(int i = 0 ; i <= n + 1 ; i++) {
            color[i] = 0 ;
        }
        flag = 1 ;
        dfs(1 , 1) ;
        if(flag == 1) 
            cout << "YES\n" ;
        else 
            cout << "NO\n" ;
        for(int i = 0 ; i <= n + 1 ; i++) {
            G[i].clear() ;
        }
    }

    return 0 ;
}
