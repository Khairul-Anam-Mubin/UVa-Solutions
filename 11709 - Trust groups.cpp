#include <bits/stdc++.h>
using namespace std ;

void fasterio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}

#define mxN 1000
map <string , int> mp ;
vector <int> G[mxN + 10] ,GR[mxN + 10] ;
vector <int> order , component ;
bool vis[mxN + 10] ;

void Graph_clear(int n) {
    for(int i = 0 ; i <= n ; i++) {
        G[i].clear() ;
        GR[i].clear() ;
    }
    mp.clear() ;
    order.clear() ;
}
void init(int n) {
    for(int i = 0 ; i <= n ; i++)
        vis[i] = 0 ;
}
void dfs1(int u ) {
    vis[u] = 1 ;
    for(int v : G[u]) {
        if(!vis[v])
            dfs1(v) ;
    }
    order.push_back(u) ;
}
void Reverse_edge(int n) {
    for(int i = 1 ; i <= n ; i++) {
        for(int j : G[i]) {
            GR[j].push_back(i) ;
        }
    }
}
void dfs2(int u) {
    vis[u] = 1 ;
    component.push_back(u) ;
    for(int v : GR[u]) {
        if(!vis[v])
            dfs2(v) ;
    }
}
int KosarajuSCC(int n , int m ) {
    init(n) ;
    for(int i = 1 ; i <= n ; i++) {
        if(!vis[i])
            dfs1(i) ;
    }
    /*cout << "top sort : " ;
    for(int i = order.size() - 1 ; i >= 0 ; i--) {
        cout << order[i] << " " ;
    }
    cout << "\n" ;
    */
    Reverse_edge(n) ;
    init(n) ;
    int cnt = 0 ;
    for(int i = order.size() - 1 ; i >= 0 ; i--) {
        int v = order[i] ;
        if(!vis[v]) {
            dfs2(v) ;
            cnt++ ;
            component.clear() ;
        }
    }
    //cout << cnt << "\n" ;
    return cnt ;
}
int main() {
    int n , m ;
    while(cin >> n >> m) {
        if(n == 0 && m == 0)
            break ;
        string dump ;
        getline(cin , dump) ;
        for(int i = 1 ; i <= n ; i++) {
            string str ;
            getline(cin , str) ;
            mp[str] = i ;
            //cout << str << " " << mp[str] << "\n" ;
        }
        for(int i = 1 ; i <= m ; i++ ) {
            string x , y ;
            getline(cin , x) ;
            getline(cin , y) ;
            int u , v ;
            u = mp[x] ;
            v = mp[y] ;
            //cout << u << " " << v << "\n" ;
            G[u].push_back(v) ;
        }
        /*for(int i = 1 ; i <= n ; i++) {
            cout << i << " : " ;
            for(int j : G[i]) {
                cout << j << " -> " ; 
            }
            cout << "\n" ;
        }*/
        int ans = KosarajuSCC(n , m) ;
        cout << ans << "\n" ;
        Graph_clear(n) ;
    }
    return 0 ;
}
