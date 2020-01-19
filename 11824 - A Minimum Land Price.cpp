#include <bits/stdc++.h>
using namespace std ;
 
#define FasterIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define precision(a) cout << fixed << setprecision(a) 
#define mxN 100000
template <typename T> T Abs(T a) {
    if(a < 0) return -a;
    else return a;
}

int main() {
    FasterIO
    int tc ;
    cin >> tc ;
    while(tc--) {
        long long n ;
        vector <long long> vec ;
        while(cin >> n && n != 0) {
            vec.push_back(n) ;
        }
        sort(vec.begin() , vec.end()) ;
        long long ans = 0 ;
        bool flag = 0 ;
        for(int i = vec.size() - 1 , p = 1 ; i >= 0 ; i-- , p++) {
            long long temp = 1 ;
            for(int j = 1 ; j <= p ; j++) {
                temp *= vec[i] ;
                if(temp > 5000000) {
                    flag = 1 ;
                    break ;
                }
            }
            if(flag) {
                break ;
            } else {
                ans += temp ;
                if(ans > 5000000) {
                    flag = 1  ;
                    break ;
                }
            }
        }
        if(ans * 2 > 5000000)
            flag = 1 ; 
        if(flag == 0) {
            cout << ans * 2 << "\n" ;
        } else {
            cout << "Too expensive\n" ;
        }
    }

    return 0 ;
}
