#include <bits/stdc++.h>

using namespace std ;

void fasrerIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}

int dx[] = { 0 , 0 , -1 , 1 } ;
int dy[] = { 1 , -1 , 0 , 0 } ;

int row = 9 , col = 9 ;
char grid[15][15] ;
int vis[15][15] ;

bool isok(int x , int y) {
    if(x >= 0 && y >= 0 && x < row && y < col) 
        return 1 ;
    return 0 ;
}
void dfs(int x , int y , int from , int to ) {
    for(int i = 0 ; i < 4 ; i++) {
        int xx = x + dx[i] ;
        int yy = y + dy[i] ;
        if(isok(xx , yy) && vis[xx][yy] == from) {
            vis[xx][yy] = to ;
            dfs(xx , yy ,from ,to) ;
        }
    }
}
int main() {
    fasrerIO() ;
    int tc ;
    cin >> tc ;
    while(tc--) {
        for(int i = 0 ; i < row ; i++) 
            for(int j = 0 ; j < col ; j++) 
                vis[i][j] = 0 ;

        int cnt4 = 0 , cnt2 = 0 ,cnt5 = 0 , cnt3 = 0 ;
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                cin  >> grid[i][j] ;
                if(grid[i][j] == 'X') {
                    vis[i][j] = 4 ;
                    cnt4++ ;
                }
                else if(grid[i][j] == 'O') {
                    vis[i][j] = 2 ;
                    cnt2++ ;
                }
            }
        }
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                if(vis[i][j] == 4) {
                    dfs(i , j , 0 , 5) ;
                }
            }
        }
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                if(vis[i][j] == 2) {
                    for(int k = 0 ; k < 4 ; k++) {
                        int xx = i + dx[k] ;
                        int yy = j + dy[k] ;
                        if(isok(xx , yy) && vis[xx][yy] == 0) {
                            vis[xx][yy] = 3 ;
                            dfs(xx , yy , 0 , 3 ) ;
                        }
                        else if(isok(xx ,yy) && vis[xx][yy] == 5) {
                            vis[xx][yy] = 1 ;
                            dfs(xx , yy , 5 , 1) ;
                        }
                    }
                }
            }
        }

        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                if(vis[i][j] == 3)
                    cnt3++ ;
                else if(vis[i][j] == 5)
                    cnt5++ ;
            }
        } 
        cout << "Black " << cnt4 + cnt5 << " White " << cnt2 +  cnt3 << "\n" ;
    }

    return 0 ;
}
