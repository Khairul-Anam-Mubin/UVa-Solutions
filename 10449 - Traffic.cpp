#include <bits/stdc++.h>
using namespace std ;
 
#define mxN 200
#define INF 1e18
struct node {
    long long u , v , w ;
    node(long long _u , long long _v , long long _w) {
        u = _u ;
        v = _v ;
        w = _w ;
    }
};
long long val[mxN + 10] ;
long long cost[mxN + 10] ;
vector <node> g ;
// Edgelist version..
void bellmanford(int nodes , int edges) {
    for(int i = 0 ; i <= nodes + 1 ; i++)
        cost[i] = INF ;
    cost[1] = 0 ;
    for(int i = 1 ; i <= nodes - 1 ; i++) {
        for(int j = 0 ; j < edges ; j++) {
            long long u = g[j].u ;
            long long v = g[j].v ;
            long long w = g[j].w ;
            if(cost[u] != INF && cost[u] + w < cost[v])
                cost[v] = cost[u] + w ;
        }
    }
    // Assuming negative cycle...
    for(int j = 0 ; j < edges ; j++) {
        long long u = g[j].u ;
        long long v = g[j].v ;
        long long w = g[j].w ;
        if(cost[u] != INF && cost[u] + w < cost[v])
            cost[v] = -INF ;
    }
}
int main() {
    int test = 0 ;
    int nodes ;
    while(cin >> nodes) {
        for(int i = 1 ; i <= nodes ; i++)
            cin >> val[i] ;
        int edges ;
        cin >> edges ;
        for(int i = 0 ; i < edges ; i++) {
            long long u , v , w ;
            cin >> u >> v ;
            w = (val[v] - val[u]) * (val[v] - val[u]) * (val[v] - val[u]) ;
            g.push_back(node(u , v , w)) ;
        }
        bellmanford(nodes , edges) ;
        int q ;
        cin >> q ;
        cout << "Set #" << ++test << "\n" ;
        while(q--) {
            int x ;
            cin >> x ;
            if(x <= 0 || x > nodes || cost[x] < 3 || cost[x] == INF)
                cout << "?\n" ;
            else
                cout << cost[x] << "\n" ;
        }  
        g.clear() ;
    } 
    return 0 ;
}
