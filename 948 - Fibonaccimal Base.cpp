#include <bits/stdc++.h>

using namespace std ;

int main() {
    int fib[40] ;
    fib[0] = 1 ;
    fib[1] = 1 ;
    for(int i = 2 ; i < 40 ; i++)
        fib[i] = fib[i - 1] + fib[i - 2] ;
    int tc ;
    scanf("%d", &tc) ;
    while(tc--) {
        int n ;
        scanf("%d" ,&n) ;
        int flag = 0 ;
        printf("%d = ",n) ;
        for(int i = 39 ; i > 0 ; i--) {
            if(n >= fib[i]) {
                n -= fib[i] ;
                flag = 1 ;
                printf("1") ;
            }
            else if(flag)
                printf("0") ;
        }
        printf(" (fib)\n") ;
    }
    return 0 ;
}
