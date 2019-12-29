#include <bits/stdc++.h>
using namespace std ;

#define mxN 200

vector <int> G[mxN + 10] ;
int color[mxN + 10] ;
int flag = 0 ;
int cnt1 , cnt2 ;

void Graph_clear(int n) {
    for(int i = 0 ; i <= n ; i++)
        G[i].clear() ;
}
void dfs(int u , int col) {
    color[u] = col ;
    for(int v : G[u]) {
        if(col == 1 && color[v] == 0) {
            dfs(v , 2) ;
            cnt2++ ;
        } else if(col == 2 && color[v] == 0) {
            dfs(v , 1) ;
            cnt1++ ;
        } else if(color[v] == color[u]) {
            flag = -1 ;
            return ;
        }
    }
    return ;
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
            G[v].push_back(u) ;
        }
        for(int i = 0 ; i <= n ; i++)
            color[i] = 0 ;
        int ans = 0 ;
        flag = 0 ;
        cnt1 = 0 , cnt2 = 0 ;
        for(int i = 0 ; i < n ; i++) {
            if(color[i] == 0) {
                dfs(i , 1) ;
                cnt1++ ;
                if(cnt2 == 0) 
                    ans += 1 ;
                else
                    ans += min(cnt1 , cnt2) ;
                cnt1 = 0 ;
                cnt2 = 0 ;
            }
        }
        if(flag == -1) 
            cout << "-1\n" ;
        else {
            cout << ans << "\n" ;
        }
        Graph_clear(n) ;
    }
    return 0 ;
}
