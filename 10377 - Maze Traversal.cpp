#include <bits/stdc++.h>

using namespace std ;


int row , col ,x , y ;
char str[70][70] ;
bool check(int xx, int yy) {
    if(xx >= 0 && yy >= 0 && xx < row && yy < col && str[xx][yy] == ' ')
        return 1 ;
    return 0 ;
}
int main() {
    int tc ;
    char co[1000] ;
    scanf("%d",&tc) ;
    while(tc--) {
        scanf("%d %d " ,&row , &col) ;
        for(int i = 0 ; i < row ; i++) {
            gets(str[i]) ;
        }
        scanf(" %d %d ",&x, &y) ;
        x-- ;
        y-- ;
        int dir = 1 ;
        bool finish = 0 ;
        while(gets(co)) {
            int len = strlen(co) ;
            if(!len)
                break ;
            for(int i = 0 ; i < len ; i++) {
                if(co[i] == 'Q') {
                    finish = 1 ;
                    break ;
                }
                else if(co[i] == 'F') {
                    if(dir == 1 && check(x - 1 , y)) {
                        x-- ;
                    }
                    else if(dir == 2 && check(x , y + 1)) {
                        y++ ;
                    }
                    else if(dir == 3 && check(x + 1 , y)) {
                        x++ ;
                    }
                    else if(dir == 4 && check(x , y - 1)) {
                        y-- ;
                    }
                }
                else if(co[i] == 'R') {
                    if(dir == 4)
                        dir = 1 ;
                    else
                        dir++ ;
                }
                else if(co[i] == 'L') {
                    if(dir == 1)
                        dir = 4 ;
                    else
                        dir-- ;
                }
            }
            if(finish)
                break ;
        }
        char s ;
        if(dir == 1)
            s = 'N';
        else if(dir == 2)
            s = 'E' ;
        else if(dir == 3) 
            s = 'S' ;
        else if(dir == 4) 
            s = 'W' ;
        printf("%d %d %c\n",x + 1 , y + 1 , s) ;
        //cout << x + 1 << " " << y + 1 << "\n" ;
        if(tc)
            printf("\n") ;
    }    
    return 0 ;
}
