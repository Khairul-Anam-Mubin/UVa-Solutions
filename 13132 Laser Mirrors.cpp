#include <bits/stdc++.h>

using namespace std ;

#define mx 100000 
int phi[mx + 10] ;
void PreCalPhi() {
   phi[1] = 1 ;
   for(int i = 2 ; i <= mx ; i++) {
        if(phi[i] == 0) {
            phi[i] = i - 1 ;
            for(int j = i + i ; j <= mx ; j += i ) {
                if(phi[j] == 0)
                    phi[j] = j ;
                phi[j] -= ( phi[j] / i ) ;
            }
        }
   }
}
int main() {
    PreCalPhi() ;
    int tc ;
    scanf( "%d" ,&tc) ;
    while(tc--) {
        int n ;
        scanf( "%d" ,&n) ;
        printf( "%d\n",phi[n]) ;
    }
    return 0 ;
}
