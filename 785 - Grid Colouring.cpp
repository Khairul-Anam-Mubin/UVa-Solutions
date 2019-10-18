#include <bits/stdc++.h>

using namespace std ;

#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)

void fasrerIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}


int dx[] = { 0 , 0 , 1 , -1 } ; 
int dy[] = { 1 , -1 , 0 , 0 } ;

string str[40] ;
int vis[40][100] ;

void dfs(int x , int y , int color) {
    if(vis[x][y] || str[x][y] == 'X')
        return ;
    vis[x][y] = 1 ;
    str[x][y] = color ;
    for(int i = 0 ; i < 4 ; i++) {
        int xx = x + dx[i] ;
        int yy = y + dy[i] ;
        dfs(xx , yy , color) ;
    }
}
int main() {
    //Fin , Fout ;

    while(true) {
        int n = 0 ;
        while(true) {
            if(!getline(cin , str[n]))
                return 0 ;
            if(str[n][0] == '_')
                break ;
            n++ ;
        }
        for(int i = 0 ; i < 40 ; i++) {
            for(int j = 0 ; j < 100 ; j++) {
                vis[i][j] = 0 ;
            }
        }
        for(int i = 0 ; i < n ; i++) {
            int len = str[i].size() ;
            for(int j = 0 ; j < len ; j++) {
                if(str[i][j] != 'X' && str[i][j] != ' ') {
                    if(!vis[i][j])
                        dfs(i , j , str[i][j]) ;
                }
            }
        }
        for(int i = 0 ; i < n ; i++) {
            cout << str[i] << "\n" ;
            str[i].clear() ;
        }
        cout << "_____________________________\n" ;
    }
    return 0 ;
}
