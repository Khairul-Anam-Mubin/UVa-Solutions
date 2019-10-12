#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n ;
    while(scanf( "%d" ,&n) == 1 && n ) {
        int dp[300] ;
        for(int i = 0 ; i < 300 ; i++)
            dp[i] = 0 ;
        int rem = 1 % n ;
        for(int i = 1; true ; i++) {
            if(dp[rem]) {
                for(int j = dp[rem] ; j < i ; j++)
                    printf("1") ;
                for(int j = dp[rem] - 1 ; j >= 0; j--)
                    printf("0") ;
                break;
            }
            dp[rem] = i;
            rem = (rem * 10 + 1) % n ; 
        }
        printf("\n") ;
    }
    return 0 ;
}
