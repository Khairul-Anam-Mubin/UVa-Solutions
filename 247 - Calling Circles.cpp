#include <bits/stdc++.h>
using namespace std ;

#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)

#define mxN 30

map <string , int> mp ;
map <int , string> name ;
vector <int> G[mxN + 10] , GR[mxN + 10] ;
vector <int> order , component ;
bool vis[mxN + 10] ;

void graph_clear(int nodes) {
    for(int i = 0 ; i <= nodes + 1 ; i++) {
        G[i].clear() ;
        GR[i].clear() ;
    }
}
void init(int nodes) {
    for(int i = 0 ; i <= nodes ; i++)
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
void reverse_edges(int nodes ,int edges) {
    for(int i = 1 ; i <= nodes ; i++) {
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
void KosarajuSCC(int nodes , int edges) {
    init(nodes) ;
    for(int i = 1 ; i <= nodes ; i++) {
        if(!vis[i])
            dfs1(i) ;
    }
    reverse_edges(nodes , edges) ;
    init(nodes) ;
    for(int i = order.size() - 1 ; i >= 0 ; i--) {
        int v = order[i] ;
        if(!vis[v]) {
            dfs2(v) ;
            for(int i = 0 ; i < component.size() ; i++) {
                if(i + 1 != component.size()) {
                    cout << name[component[i]] << ", " ;
                } else {
                    cout << name[component[i]] << "\n" ;
                }
            }
            component.clear() ;
        }
    }
}
int main() {
    //Fin ;
    //Fout ;
    int nodes , edges , test = 0 ;
    while(cin >> nodes >> edges) {
        if(nodes == 0 && edges == 0)
            break ;
        if(test)
            cout << "\n" ;
        int cnt = 1 ;
        for(int i = 1 ; i <= edges ; i++) {
            string u , v ;
            cin >> u >> v ;
            if(mp[u] == 0) {
                mp[u] = cnt ;
                name[cnt] = u ;
                cnt++ ;
            }
            if(mp[v] == 0) {
                mp[v] = cnt ;
                name[cnt] = v ;
                cnt++ ;
            }
            G[mp[u]].push_back(mp[v]) ;
        }
        cout << "Calling circles for data set " << ++test << ":\n" ;
        KosarajuSCC(nodes , edges) ;
        //cout << "\n" ;
        graph_clear(nodes) ;
        name.clear() ;
        mp.clear() ;
    }
    return 0 ;
}
