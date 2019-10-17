#include <bits/stdc++.h>

using namespace std ;

int dx[] = { 0 , 0 , 1 , -1 } ;
int dy[] = { 1 , -1 ,0 , 0 } ;
int n , m ;
char grid[55][55] ;
bool vis[55][55] ;
int ans = 0 ;
bool isok(int x , int y) {
    if(x >= 0 && y >= 0 && x < n && y < m) {
        return 1 ;
    }
    return 0 ;
}
void dfs(int x , int y , char ch) {
    if(!vis[x][y])
        ans++ ;
    vis[x][y] = 1 ;
    for(int i = 0 ; i < 4 ; i++) {
        int xx = x + dx[i] ;
        int yy = y + dy[i] ;
        if(isok(xx ,yy) && !vis[xx][yy] && grid[xx][yy] == ch) {
            dfs(xx , yy , ch) ;
        } 
    }
}
bool cmp(pair <int ,char> a , pair <int , char> b) {
    if(a.first > b.first)
        return 1 ;
    else if(a.first < b.first) 
        return 0 ;
    else if(a.first == b.first) {
        if(a.second < b.second)
            return 1 ;
        else 
            return 0 ;
    }
}
int main() {
    int test = 0 ;
    while(scanf( "%d%d" , &n , &m) == 2) {
        if(!n && !m)
            break ;
        for(int i = 0 ; i < n ; i++)
            scanf("%s" , grid[i]) ;
        vector <pair <int , char> > vec ;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                ans = 0 ;
                if(!vis[i][j] && grid[i][j] != '.') {
                    dfs(i , j , grid[i][j]) ;
                    vec.push_back(make_pair(ans , grid[i][j])) ;
                }
            }
        }
        sort(vec.begin() , vec.end() , cmp) ;
        printf( "Problem %d:\n" ,++test) ;
        for(int i = 0 ; i < vec.size() ; i++) {
            //cout << vec[i].second << " " << vec[i].first << "\n" ;
            printf( "%c %d\n" , vec[i].second , vec[i].first) ;
        }
        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0 ; j <= m ; j++) {
                vis[i][j] = 0 ;
            }
        }
    }
    return 0 ;
}
