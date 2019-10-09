#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n  ;
    while(scanf( "%d" , &n) == 1 && n) {
        vector <int> vec ;
        for(int i = 0 ; i < n ; i++) {
            int x ;
            scanf( "%d",&x) ;
            if(x > 0)
                vec.push_back(x) ; 
        }
        if(vec.size() == 0) 
            printf("0\n") ;
        else {
            for(int i = 0 ; i < vec.size() ; i++) {
                if(i == 0)
                    printf("%d" , vec[i]) ;
                else 
                    printf(" %d" , vec[i]) ;
            }
            printf("\n") ;
        }
    }
    return 0 ;
}   
