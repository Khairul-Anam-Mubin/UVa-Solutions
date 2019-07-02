#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
struct node{
    ll x , cost ;
    node(ll _x , ll _cost) {
        x = _x ;
        cost = _cost ;
    }
    bool operator < (const node& p) const {
        return cost > p.cost ;
    }
};
vector <node> G[20010] ;
ll dist[20010] ;
void Fill(ll nodes) {
    for(ll i = 0 ; i <= nodes + 1 ; i++){
        G[i].clear();
        dist[i] = 1e18 ;
    }
}
ll dijkstra(ll from , ll to , ll nodes) {
    priority_queue <node> pq ;
    dist[from] = 0 ;
    pq.push(node(from , 0)) ;
    while(!pq.empty()) {
        node temp = pq.top() ;
        ll u = temp.x ;
        ll wu = temp.cost ;
        pq.pop() ;
        if(u == to)
            return dist[to] ;
        if(dist[u] < wu)
            continue ;
        for(ll i = 0 ; i < G[u].size() ; i++) {
            ll v = G[u][i].x ;
            ll wv = G[u][i].cost ;
            if(wu + wv < dist[v]) {
                dist[v] = wu + wv ;
                pq.push(node(v,dist[v]));
            }
        }
    }
    return -1 ;
}
int main() {
    int tc ,t = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        ll nodes , edge ,from , to ;
        scanf("%lld%lld%lld%lld",&nodes,&edge,&from,&to) ;
        Fill(nodes) ;
        for(int i = 0 ; i < edge ; i++) {
            ll u , v , w ;
            scanf("%lld%lld%lld",&u,&v,&w) ;
            node temp(v,w) ;
            G[u].push_back(temp) ;
            temp.x = u ;
            G[v].push_back(temp) ;
        }
        ll ans = dijkstra(from , to , nodes) ;
        if(ans == -1)
            printf("Case #%d: unreachable\n",++t) ;
        else
            printf("Case #%d: %lld\n",++t , ans) ;
    }
    return 0;
}
