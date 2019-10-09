#include <bits/stdc++.h>

using namespace std ;

#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)

int main() {
    //Fin , Fout ;
    int tc , test = 0 ;
    cin >> tc ;
    int h = tc ;
    while(tc--) {
        int n ;
        cin >> n ;
        getchar() ;
        cout << "Case " << ++test << ":\n" ;
        for(int i = 0 ; i < n ; i++) {
            string str ;
            getline(cin , str) ;
            int len = str.size() ;
            string ss ;
            for(int i = 0 ; i < len ; i++) {
                if(str[i] != ' ') {
                    //cout << str[i] ;
                    ss.push_back(str[i]) ;
                }
                else {
                    while(str[i] == ' ') {
                        i++ ;
                    }
                    i--;
                    ss.push_back(' ') ;
                }
            }
            cout << ss << "\n" ;
        }
        if(h > test)
            cout << "\n" ;
    }
    return  0 ; 
}
