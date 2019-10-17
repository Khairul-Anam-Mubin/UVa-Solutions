#include <bits/stdc++.h>

using namespace std ;

#define Fout     freopen("output.txt","w",stdout)
#define Fin      freopen("input.txt","r",stdin)

int dx[] = {0,0,-1,1,-1,-1,1,1,0};
int dy[] = {1,-1,0,0,-1,1,-1,1,0};
string str[30] ;
bool vis[30][30] ;
int row , col ;
int cnt = 0 ;
void dfs(int x , int y) {
    if(!vis[x][y] && str[x][y] == '1')
        cnt++ ;
    vis[x][y] = 1 ;
    for(int i = 0 ; i < 8 ; i++) {
        int xx = x + dx[i] ;
        int yy = y + dy[i] ;
        if(xx < row && yy < col && xx >= 0 && yy >= 0 && !vis[xx][yy] && str[xx][yy] == '1') {
            dfs(xx , yy) ;
        }
    }
}
int main() {
    //Fin ;
    //Fout ;
    int tc ;
    cin >> tc ;
    string s ;
    getline(cin ,  s) ;
    getline(cin ,  s) ;
    while(tc--) {
        int i = 0 ;
        while(getline(cin , s)) { 
            if(s == "")
                break ;
            str[i++] = s ;
        }
        row = i ;
        col = str[0].size() ;
        int ans = -100000 ;
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                cnt = 0 ;
                if(str[i][j] == '1' && !vis[i][j]) {
                    dfs(i , j) ;
                    ans = max(cnt , ans) ;
                }
            }
        }
        if(ans == -100000)
            ans = 0;
        //cout << row << "\n" ;
        if(tc) {
            cout << ans << "\n\n" ;
        }
        else
            cout << ans << "\n" ;
        for(int i = 0 ; i < 30 ; i++)
            str[i].clear() ;
        for(int i = 0 ; i < 30 ; i++)
            for(int j = 0 ; j < 30 ; j++)
                vis[i][j] = 0 ;
    }
    return 0 ;
}
