#include <bits/stdc++.h>

using namespace std ;

#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)

int row , col , query ; 
char G[110][110] , Q[50010] ;

bool check(int x , int y) {
    if(x >= 0 && y >= 0 && x < row && y < col && G[x][y] != '#')
        return 1 ;
    return 0 ;
}
int main() {
    //Fin ;
    //Fout ;
    while(cin >> row >> col >> query) {
        if( row + col + query == 0 )
            break ;
        int sx = -1 , sy = -1 , dir = -1 ;
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) { 
                cin >> G[i][j] ; 
                if(G[i][j] == 'N') { 
                    sx = i ; 
                    sy = j ; 
                    dir = 1 ; 
                } 
                else if(G[i][j] == 'L') { 
                    sx = i ;
                    sy = j ;
                    dir = 2 ;
                }
                else if(G[i][j] == 'S') {
                    sx = i ;
                    sy = j ;
                    dir = 3 ;
                }
                else if(G[i][j] == 'O') {
                    sx = i ;
                    sy = j ;
                    dir = 4 ;
                }
            }
        }
        cin >> Q ;
        int cnt = 0 ;
        for(int i = 0 ; i < query ; i++) {
            if(Q[i] == 'F') {
                if(dir == 1 && check(sx - 1 , sy)) {
                    sx-- ;
                }
                else if(dir == 2 && check(sx , sy + 1)) {
                    sy++ ;
                }
                else if(dir == 3 && check(sx + 1 , sy)) {
                    sx++ ;
                }
                else if(dir == 4 && check(sx , sy - 1)) {
                    sy-- ;
                }
                if(G[sx][sy] == '*') {
                    cnt++ ;
                    G[sx][sy] = '.' ;
                }
            }
            else if(Q[i] == 'E') {
                if(dir == 1)
                    dir = 4 ;
                else
                    dir-- ;
            }
            else if(Q[i] == 'D') {
                if(dir == 4)
                    dir = 1 ;
                else
                    dir++ ;
            }
        }
        cout << cnt << "\n" ;
    }
    return 0 ;
}
