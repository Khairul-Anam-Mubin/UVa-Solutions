#include <bits/stdc++.h>

using namespace std ;

int main() {    
    int tc , test = 0 ;
    scanf("%d",&tc) ;
    while(tc--) {
        long long n ;
        scanf("%lld" , &n) ;
        long long ans = (n * (n - 1)) / 2 ;
        printf("Case %d: " , ++test) ; 
        if(ans % 2 == 0) {
            printf("%lld\n", ans / 2) ;
        }
        else {
            printf("%lld/2\n" ,ans) ;
        }
    }
    return 0 ;  
}
