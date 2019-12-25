#include <bits/stdc++.h>
using namespace std ;

#define mxN 10000
#define INF 1e9
vector <pair <long long , int> > G[mxN + 10] ;
long long cost[mxN + 10][2] ;

void graph_clear(int nodes) {
    for(int i = 0 ; i <= nodes ; i++)
        G[i].clear() ;
}
long long dijkstra(int start ,int destination , int nodes ,int edges) {
    for(int i = 0 ; i <= nodes ; i++) {
        cost[i][0] = cost[i][1] = INF ;
    }
    priority_queue <pair <long long , pair <int , int >> > pq ;
    cost[1][0] = 0 ;
    cost[1][1] = 0 ;
    pq.push(make_pair(0 , make_pair(1 , 0))) ;
    while(!pq.empty()) {
        int u = pq.top().second.first ;
        int mark = pq.top().second.second ;
        long long wu = -pq.top().first ;
        pq.pop() ;
        for(auto it : G[u]) {
            int v = it.second ;
            long long wv = it.first ;
            int nex = (mark + 1) % 2 ;
            if(cost[v][nex] > wu + wv) {
                cost[v][nex] = wu + wv ;
                pq.push(make_pair(-cost[v][nex] , make_pair(v , nex))) ;
            }
        }
    }
    return cost[destination][0] ;
}
int main() {
    int nodes , edges ;
    while(cin >> nodes >> edges) {
        for(int i = 0 ; i < edges ; i++) {
            int u , v , w ;
            cin >> u >> v >> w ;
            G[u].push_back(make_pair(w , v)) ;
            G[v].push_back(make_pair(w , u)) ;
        }   
        int start = 1 ;
        int destination = nodes ;
        long long ans = dijkstra(start , destination , nodes , edges) ;
        if(ans == INF)
            ans = -1 ;
        cout << ans << "\n" ;
        graph_clear(nodes) ;
    }
    return 0 ;
}
