#include <bits/stdc++.h>

using namespace std ;


int dx[] = { 0 , 0 , 1 , -1 } ;
int dy[] = { 1 , -1 , 0 , 0 } ;
char grid[60][60] ;
bool vis[60][60] ;
int row ,col ;
int ans = 0 ;
bool isok(int x , int y) {
    if(x <= row && y <= col  && x >= 0 && y >= 0)
        return 1 ;
    return 0 ; 
}
void dfs(int x ,int y) {
    if(grid[x][y] == '#' || vis[x][y])
        return ;
    if(grid[x][y] == 'G')
        ans++ ;
    vis[x][y] = 1 ;
    for(int i = 0 ; i < 4 ; i++) {
        int xx = x + dx[i] ;
        int yy = y + dy[i] ;
        if(isok(xx , yy) && grid[xx][yy] == 'T')
            return ;
    }
    for(int i = 0 ; i < 4 ; i++) {
        int xx = x + dx[i] ;
        int yy = y + dy[i] ;
        if(isok(xx , yy))
            dfs(xx , yy) ;
    }
}
int main() {
    while(scanf( "%d%d" , &col , &row) == 2 ) {
        for(int i = 0 ; i < row ; i++)
            scanf("%s" , grid[i]) ;
        for(int i = 0 ; i <= row + 1 ; i++) {
            for(int j = 0 ; j <= col + 1 ; j++ )
                vis[i][j] = 0 ;
        }
        ans = 0 ;
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                if(grid[i][j] == 'P') {
                    dfs(i , j) ;
                    break ;
                }
            }
        }
        printf("%d\n" ,ans) ;
    }
    return 0 ;
}
