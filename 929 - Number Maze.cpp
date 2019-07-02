#include <bits/stdc++.h>

using namespace std ;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};
struct node{
    int x , y , cost ;
    node(int _x , int _y , int _cost) {
        x = _x ;
        y = _y ;
        cost = _cost ;
    }
    bool operator < (const node& p) const {
        return cost > p.cost ;
    }
};
int grid[1010][1010] ;
int dist[1010][1010] ;
void Fill(int row ,int col) {
    for(int i = 0 ; i <= row + 1 ; i++) {
        for(int j = 0 ; j <= col + 1 ; j++) {
            dist[i][j] = 1e9 ;
        }
    }
}
int dijkstra(int row,int col) {
    Fill(row , col) ;
    priority_queue <node> pq ;
    pq.push(node(1 , 1 , grid[1][1])) ;
    dist[1][1] = grid[1][1] ;
    while(!pq.empty()) {
        node top = pq.top() ;
        pq.pop() ;
        int a = top.x ;
        int b = top.y ;
        if(a == row && b == col)
            return dist[row][col] ;
        if(top.cost > dist[a][b])
            continue;
        for(int i = 0 ; i < 4 ; i++) {
            int x = a + dx[i] ;
            int y = b + dy[i] ;
            if(x <= row && y <= col && x >= 1 && y >= 1) {
                int wt = grid[x][y] ;
                if(wt + top.cost < dist[x][y]) {
                    dist[x][y] = wt + top.cost ;
                    pq.push(node(x,y,dist[x][y])) ;
                }
            }
        }
    }
    return dist[row][col] ;
}
int main() {
    //freopen("out.txt","w",stdout);
    int tc ;
    scanf("%d",&tc) ;
    while(tc--) {
        int row , col ;
        scanf("%d%d",&row,&col) ;
        for(int i = 1 ; i <= row ; i++) {
            for(int j = 1 ; j <= col ; j++) {
                scanf("%d",&grid[i][j]) ;
            }
        }
        int ans = dijkstra(row , col) ;
        printf("%d\n",ans);
    }
    return 0;
}
