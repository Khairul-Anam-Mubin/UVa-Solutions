#include <bits/stdc++.h>

using namespace std ;

int n , m  , s ;
char G[15][15] ;
int vis[15][15] ;
int step = -1 ;
int tot = -1 ;
void dfs(int i , int j ,int cnt) {
    int x , y ;
    if(G[i][j] == 'N') {
        x = i - 1 ;
        y = j ;
    }
    else if(G[i][j] == 'S') {
        x = i + 1 ;
        y = j ;
    }
    else if(G[i][j] == 'E') {
        x = i ;
        y = j + 1 ;
    }
    else if(G[i][j] == 'W') {
        x = i ;
        y = j - 1 ;
    }
    if(x >= 0 && y >= 0 && x < n && y < m) {
        if(vis[x][y] == -1) {
            cnt++ ;
            vis[x][y] = cnt ;
            dfs(x , y , cnt) ;
        }
        else {
            cnt++ ;
            tot = vis[x][y] ;
            step = cnt ;
        }
    }
    else {
        cnt++ ;
        step = cnt ;
    }
}
int main() {
    while(cin >> n >> m >> s) {
        if(n + m + s == 0)
            break ;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                cin >> G[i][j] ;
                //vis[i][j] = -1 ;
            }
        }
        step = -1 ;
        tot = -1 ;
        memset(vis , -1 , sizeof vis) ;
        vis[0][s - 1] = 0 ;
        dfs(0 , s - 1 , 0) ;
        if(tot == -1) {
            cout << step << " step(s) to exit\n" ;
        }
        else {
            step -= tot ;
            cout << tot << " step(s) before a loop of " << step <<" step(s)\n" ;
        }
        //cout << step << " " << tot << "\n" ;
    }
    return 0 ;
}
